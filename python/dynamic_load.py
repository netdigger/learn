import importlib
import sys

modules_path = "./modules"
sys.path.append(modules_path)

module_classes = {}

for dirpath, dirnames, filenames in os.walk(modules_path):
    for name in filenames:
        if name.endswith(".py"):
            module = importlib.import_module(os.path.splitext(name)[0])
            class_name = dir(module)[0]
            module_classes[class_name] = getattr(module, class_name, None)

for i in module_classes:
    obj = module_classes[i]()
    obj.show()
