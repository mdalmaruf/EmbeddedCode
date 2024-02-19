#Using Multithreading for Performance Improvement

# Python example using threading
import threading

def worker():
    print("Worker thread is executing")

threads = []
for i in range(5):
    t = threading.Thread(target=worker)
    threads.append(t)
    t.start()
