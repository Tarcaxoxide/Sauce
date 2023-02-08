//void (*CallBack)(_std::deque<_std::string*>& ArgBuffer)

CmdStr_st{"Test",[](_std::deque<_std::string>& Args){
    _std::cout<<"Hello World!"<<_std::endl;
}}