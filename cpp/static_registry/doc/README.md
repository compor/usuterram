
# Implementing static registration of plugins in C++

## Description

Exploring how to decouple plugins from actual creation and registration to a
main decoupled infrastructure, mimicking the legacy LLVM pass manager in a very
limited sense.

Also, used lots of stuff from [here](http://accu.org/index.php/journals/597).


## Notes

- currently implemented with static linking of shared objects


## TODO

- explore dynamic linking with dlopen and Boost


