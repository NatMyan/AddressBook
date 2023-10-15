struct base {
    int a = 5;
};

class derived : public base {
    public:
        int getB () {
            return b;
        }
    private:
        int b = 8;
};

int main () {
    derived a;
}