// In this example, both increment() and getCount() methods are synchronized on the same intrinsic lock (the instance of Counter). 
// If multiple threads frequently call these methods, threads calling getCount() will be blocked even if no thread is updating the counter, leading to unnecessary contention.

// public class Counter {
//     private int count = 0;

//     public synchronized void increment() {
//         count++;
//     }

//     public synchronized int getCount() {
//         return count;
//     }
// }


// ===========================================================

// To reduce lock contention, especially when read operations (getCount()) are more frequent than write operations (increment()), we can use a ReadWriteLock.
// This lock allows multiple threads to read concurrently but ensures exclusive access for write operations.

import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class CounterWithReadWriteLock {
    private int count = 0;
    private final ReadWriteLock lock = new ReentrantReadWriteLock();
    private final java.util.concurrent.locks.Lock readLock = lock.readLock();
    private final java.util.concurrent.locks.Lock writeLock = lock.writeLock();

    public void increment() {
        writeLock.lock();
        try {
            count++;
        } finally {
            writeLock.unlock();
        }
    }

    public int getCount() {
        readLock.lock();
        try {
            return count;
        } finally {
            readLock.unlock();
        }
    }
}
