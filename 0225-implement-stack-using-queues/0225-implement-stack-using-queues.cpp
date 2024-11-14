class MyStack {
public:
    queue<int> mainq,tempq;
    int size ;
    MyStack() {
        size =0;
    }
    
    void push(int x) {
        size++;
        mainq.push(x);
        //transfer the elements to the tempq
        for(int i=0;i<size-1;i++){
            tempq.push(mainq.front());
            mainq.pop();
        }

        //tranfer them back to the mainq
        while(!tempq.empty()){
            mainq.push(tempq.front());
            tempq.pop();
        }

    }
    
    int pop() {
        if(mainq.empty())return -1;
        size--;
        int val =mainq.front();
        mainq.pop();
        return val;
    }
    
    int top() {
        if(mainq.empty())return -1;
        return mainq.front();
    }
    
    bool empty() {
        return mainq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */