# Python Notes

- Dynamically import modules -- `dynamic_load.py`
- Home directory problem -- `write_file.py`

## Dynamic import modules

Package _importlib_ is used to load modules dynamically.
The directory where modules are saved should be add to the module search path.

    import importlib
    import sys

    modules_path = "./modules"
    sys.path.append(modules_path)

After that, `importlib.import_modul` can be used to dynamically import modules.

    module = importlib.import_module(module_name)

The `module_name` is the the module file name without extent file name. 
For example, if the module file name is: `module_a.py`, 
the `module_name` is `module_a`:w

Normally, `dir(module)` is used to list all attributes of a module. 

Function _getattr_ is used to return the value of named attribute in module.

    module_class = getattr(module, class_name, None)

Lastly, the new class object is create by the flowing code:

    obj = module_classe()

## Home direcotry

If a path start with "~", it will not be used in open file. 
So the function `expanduser` must be used to convert the path 
to absolute path.

    path = os.path.expanduser("~/test.txt")

