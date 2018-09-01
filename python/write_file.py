import os

path = os.path.expanduser("~/test.txt")
tmp = open(path, "w")
tmp.write("test")
tmp.close()
