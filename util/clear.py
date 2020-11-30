import os
import shutil

root_dir = os.getcwd()
for current_path, subdirs, files in os.walk(root_dir):
    for subdir in subdirs:
        if subdir.endswith('.o.dSYM'):
            shutil.rmtree(os.path.join(current_path, subdir))
    for file in files:
        with open(os.path.join(current_path, file)):
            if file.endswith('.o'):
                os.remove(os.path.join(current_path, file))