#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
    public:
        Observer();
        void virtual notify()=0;
        virtual ~Observer();
    protected:
    private:
};

#endif // OBSERVER_H
