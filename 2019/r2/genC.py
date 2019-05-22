import random
import subprocess
import os
import io

while True:
    fp = io.StringIO()
    print(1, file=fp)
    print(5, file=fp)
    for i in range(5):
        print(random.randint(i*10, i*20), random.randint(i*10, i*20), file=fp)

    out1 = subprocess.check_output(["./a.exe"], input=fp.getvalue().encode('utf8'))
    out2 = subprocess.check_output(["./C2"], input=fp.getvalue().encode('utf8'))

    if out1 != out2:
        print(fp.getvalue())
        break


# os.system("./a.exe < t1")
# os.system("./C2 < t1")
