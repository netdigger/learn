import importlib
import sys
import os

modules_path = "./modules"
sys.path.append(modules_path)

class_names = ["ModuleB", "ModuleC", "ModuleA"]
modules = []
module_classes = {}

for dirpath, dirnames, filenames in os.walk(modules_path):
    for name in filenames:
        print(name)
        if name.endswith(".py"):
            modules.append(importlib.import_module(os.path.splitext(name)[0]))

for class_name in class_names:
    print(class_name)
    for index, module in enumerate(modules):
        module_class = getattr(module, class_name, None)
        if module_class is not None:
            print(index)
            module_classes[class_name] = module_class
            break

for i in module_classes:
    print(i)
    obj = module_classes[i]()
    obj.show()

module = importlib.import_module("module_a")
module_class = getattr(module, "ModuleC", None)
module_class().show()
module_class = getattr(module, "ModuleA", None)
module_class().show()
