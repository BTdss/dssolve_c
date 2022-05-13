import os
import shutil
import platform


FOLDER = "dssolve_c"
sys_name = platform.system()

os.system(f"cmake -DCMAKE_BUILD_TYPE=Release -S . -B build")

if sys_name == "windows":
    os.system("cmake --build build --config Release")
else:
    os.system("cmake --build build")

shutil.make_archive(f"{FOLDER}_{sys_name.lower()}_x64", 'zip', FOLDER)
