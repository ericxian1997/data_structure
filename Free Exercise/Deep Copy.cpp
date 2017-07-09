    #define NULL 0
    class Date
    {
    public:
        Date(int y, int m, int d) { year=y; month=m; day=d; }
        Date(const Date& another) {year = another.year; month = another.month; day = another.day;}
    private:
        int year, month, day;
    };

    class Person
    {
    public:
        Person(int id, int year, int month, int day) {
            this->id = id;
            birthDate = new Date(year, month, day);
        }

        Person(Person& another)
        {
            id = another.id;
            if(birthDate!=NULL) delete []birthDate;
            birthDate = new Date(*another.birthDate);
        }
        //Person() {id = 0; birthDate = NULL;}
        Person& operator = (Person& another)
        {
            id = another.id;
            if(birthDate!=NULL) delete []birthDate;
            birthDate = new Date(*another.birthDate);
            return *this;
        }
        ~Person() { delete birthDate; }
        int getId() { return id; }
        Date* getBirthDate() { return birthDate; }
    private:
        int id;
        Date* birthDate;
    };

    int main()
    {

    }
