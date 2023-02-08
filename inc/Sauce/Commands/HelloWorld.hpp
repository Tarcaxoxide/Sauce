//void (*CallBack)(_std::deque<_std::string*>& ArgBuffer)

{[](_std::deque<_std::string*>& Args){
    if(*(Args[0]) != "Test")return;
    _std::cout<<"Hello World!"<<_std::endl;
}}