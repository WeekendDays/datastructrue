#ifndef QUEUE
#define QUEUE

class Queue{
	private:
	    void operator=(const Queue&) {}   
		Queue(const Queue&) {} 
    public:
	    Queue(){}         
		virtual ~Queue() {}
		virtual void clear() = 0;
		virtual void enqueue(int) = 0;
		virtual int dequeue() = 0;
		virtual int frontValue() = 0;
		virtual int length() = 0;
};
#endif

