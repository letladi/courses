class cashRegister
{
public:
    int getCurrentBalance() const;
    void acceptAmount(int);
    cashRegister();
    cashRegister(int);
private:
    int cashOnHand;
};