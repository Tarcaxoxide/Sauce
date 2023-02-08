//void (*CallBack)(_std::deque<_std::string*>& ArgBuffer)

CmdStr_st{"Clear",[](_std::deque<_std::string>& Args,Shell_cl& Shell){
    Shell.ShellClear(true);
}}