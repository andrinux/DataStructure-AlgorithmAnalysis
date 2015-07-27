#include <iostream>
#include <stack>
#include <vector>

int times = 0;
void print_hanoi(std::vector<std::stack<int> > H);

//move(start tile, end tile, from 'from' rod, to 'to' rod)
void move(std::vector<std::stack<int> >& H, int s, int e, int from, int to, int via) {
    if(s == e) {
        H[from].pop();
        H[to].push(s);
        print_hanoi(H);
        times++;
        return;
    }
    move(H, s,e-1,from, via, to);
    move(H, e,e,from, to, via);
    move(H, s,e-1, via, to, from);
}

void hanoi(std::vector<std::stack<int> >& H, int n) {
    if (n == 1) {
        H[0].pop();
        H[2].push(n);
        return;
    }
    move(H,1,n-1,0,1,2);
    move(H,n,n,0,2,1);
    move(H,1,n-1,1,2,0);
    //times+=3;
}

void print_hanoi(std::vector<std::stack<int> > H) {
    std::cout<<"|\n-------------\n";
    for (int i = 0; i < 3; i++) {
        int N = H[i].size();
        std::vector<int> one_stack;
        for (int j = 0; j < N; j++) {
            one_stack.push_back(H[i].top());
            H[i].pop();
        }
        std::cout<<"|";
        for(int j = one_stack.size()-1; j >= 0; j--) {
            std::cout<<one_stack[j]<<" ";
        }
        one_stack.clear();
        std::cout<<"\n-------------\n";
    }
    std::cout<<"|\n\n\n";
}

int main(int argc, char* argv[]) {
    std::stack<int> c;
    std::vector<std::stack<int> > H;
    H.push_back(c);
    H.push_back(c);
    H.push_back(c);
    int N = atoi(argv[1]);
    for (int i = N; i > 0; i--) {
        H[0].push(i);
    }
    print_hanoi(H);
    hanoi(H,N);
    std::cout<<"After "<<times<< " moves we got:\n";
    print_hanoi(H);
}

