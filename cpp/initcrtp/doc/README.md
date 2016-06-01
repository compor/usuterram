
# Instatiation during construction of template members of class templates

## Description

A template member of a class template is not instantiated unless it is used, so
for the implicit call during constuction we need to force instatiation.
This approach does not involve any explicit actions from the users of the class.

Note that this is specific for static data members.

Solution found [here](http://goo.gl/71twiD).


