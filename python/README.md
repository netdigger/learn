# Python Notes

## Dynamic import modules

Package _importlib_ is used to load modules dynamically.
The directory where modules are saved should be add to the module search path.

    import importlib
    import sys

    modules_path = "./modules"
    sys.path.append(modules_path)

After that, _importlib.import_module_ can be used to dynamically import modules.

    module = importlib.import_module(module_name)

The _module_name_ the the module file name without extent file name. 
For example, if the module file name is: _module_a.py_, 
the _module_name_ is _module_a_

Normally, if the module has only one class, the class name is the first elements
in attribute list. 

    class_name = dir(module)[0]

Function _getattr_ is used to return the value of named attribute in module.

    module_class = getattr(module, class_name, None)

Lastly, the new class object is create by the flowing code:

    obj = module_classe()
