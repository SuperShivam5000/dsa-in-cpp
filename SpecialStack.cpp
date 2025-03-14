class SpecialStack {
    public:
        stack<int> s;
        int mini=INT_MAX;
    void push(int data) {
            if(data<mini){
            s.push(data*2-mini);
            mini=data;
        }
        else s.push(data);
    }

    void pop() {
        if(s.empty()) return;
        int data=s.top();
        if(data<mini){
            mini=mini*2-data;
        }
        s.pop();
    }

    int top() {
        if (s.empty()) return -1;

        int data = s.top();
        if (data < mini) {
            return mini;
        } 
        return data;
    }

    int getMin() {
        return mini;
    }  
};