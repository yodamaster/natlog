#ifndef INCLUDED_SIGNAL_
#define INCLUDED_SIGNAL_

#include <vector>
#include <cstddef>
#include <signal.h>

class SignalHandler
{
    friend class Signal;

    public:
        virtual ~SignalHandler();
    private:
        virtual void signaled(size_t signum) = 0;
};

class Signal
{
    typedef std::vector<SignalHandler *> SignalHandlerVector;
    std::vector<SignalHandlerVector> d_signals;

    static Signal *s_signal;

    public:
        static Signal &instance();
        
        Signal(Signal const &) = delete;
        Signal &operator=(Signal const &) = delete;

        void add(size_t signum, SignalHandler &object);
        void ignore(size_t signum);
        void reset(size_t signum);

    private:
        Signal();

        static void verify(size_t signum, char const *member);
        static void handler(int signum);
};
        
#endif