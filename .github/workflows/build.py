import os
import shutil
import platform


FOLDER = "dssolve_c"
sys_name = platform.system()

os.system(f"cmake -DCMAKE_BUILD_TYPE=Release -S . -B build")

os.system("cmake --build build --config Release")

shutil.make_archive(f"{FOLDER}_{sys_name.lower()}_x64", 'zip', FOLDER)
