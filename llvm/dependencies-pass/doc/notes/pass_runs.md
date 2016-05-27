
# Notes on pass runs

## Details

Using opt of LLVM 3.8.1 which means the Legacy Pass Manager is in use.

Info to clarify: [github issue]([https://goo.gl/ncv66h)

## Observations

### Dependencies

A function pass manager is run as a pass of the module pass manager. Any
dependencies of module passes on function passes dictate the order of execution.
Any explicit ordering of the command line arguments of passes will affect the
where the function pass manager will appear regardless of another pass's
requirements depending on the scope of operation (type of IR unit).

If a function pass depends on a module pass, the module pass will run prior to
the execution of the function pass manager that manages the specific function
pass. If that module pass is explicitly specified prior to the function pass
that requires it, it will still appear once. 

**TODO verify**
My guess is that this happends due to the scope of operation on the IR unit (a
module includes 0 or more functions).

- check opt code
- add BB pass

### Pass output

A function pass required by a module pass needs to be run on the specific IR
unit in order to produce output (stderr/stdout).

### Pass structure debug output

There seems to be a separate structure debug output for function passes that are 
required but not provided explicitly on the command line (they don't need to
be).


### Examples

#### Pass structure without any pass dependency

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass2 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass2 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    Pass2
    FunctionPass Manager
      Module Verifier
```

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass1 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass1 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    FunctionPass Manager
      Pass1
      Module Verifier
```

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass1 -pass2 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass1 -pass2 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    FunctionPass Manager
      Pass1
    Pass2
    FunctionPass Manager
      Module Verifier
```

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass2 -pass1 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass2 -pass1 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    Pass2
    FunctionPass Manager
      Pass1
      Module Verifier
```


#### Pass structure with pass dependency

- All passes preserve everything.

##### Module pass depends on function pass

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass2 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass2 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    Pass2
      Unnamed pass: implement Pass::getPassName()
    FunctionPass Manager
      Module Verifier
Pass Arguments:  -pass1
  FunctionPass Manager
    Pass1
```

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass1 -pass2 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass2 -pass1 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    Pass2
      Unnamed pass: implement Pass::getPassName()
    FunctionPass Manager
      Pass1
      Module Verifier
Pass Arguments:  -pass1
  FunctionPass Manager
    Pass1
```

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass2 -pass1 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass1 -pass2 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    FunctionPass Manager
      Pass1
    Pass2
      Unnamed pass: implement Pass::getPassName()
    FunctionPass Manager
      Module Verifier
Pass Arguments:  -pass1
  FunctionPass Manager
    Pass1
```

##### Function pass depends on module pass

- All passes preserve everything.

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass1 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass2 -pass1 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    Pass2
    FunctionPass Manager
      Pass1
      Module Verifier
```

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass1 -pass2 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass2 -pass1 -pass2 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    Pass2
    FunctionPass Manager
      Pass1
    Pass2
    FunctionPass Manager
      Module Verifier
```

Executed as:

`opt -load pass/libLLVMMyPasses.so -pass2 -pass1 main.bc -debug-pass=Structure`

output:

```
Pass Arguments:  -targetlibinfo -tti -pass2 -pass1 -verify
Target Library Information
Target Transform Information
  ModulePass Manager
    Pass2
    FunctionPass Manager
      Pass1
      Module Verifier
```

