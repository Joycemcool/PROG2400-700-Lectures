#include <iostream>
#include <memory>

struct Student {
    std::string _id;
    std::string _name;
};

class SmartPtr {
    Student *_data{nullptr};

    // private?? why??
    explicit SmartPtr(Student *data) : _data(data) {
    }

public:
    SmartPtr(SmartPtr &&ptr) noexcept {
        _data = ptr._data;
        ptr._data = nullptr;
    }

    ~SmartPtr() {
        if (_data) std::cout << "deallocating student" << std::endl;
        delete _data;
    }

    static SmartPtr make_smartptr() {
        std::cout << "allocating new student" << std::endl;
        return SmartPtr(new Student());
    }

    [[nodiscard]] Student *get() const { return _data; }

    Student *operator->() const { return _data; }
};

int main() {

    auto print = [](auto &desc, auto &s) {
        std::cout << desc << s->_name << " (" << s->_id << ") " << std::endl;
    };

    {
        // regular pointer
        auto s = new Student({"W111222", "john"});
        print("OLD PTR: ", s);

        // shallow copy of john
        auto s2 = s;
        print("SHALLOW COPY: ", s2);

        // deep copy of john (leave john alone)
        auto s3 = new Student({s->_id, s->_name});
        print("DEEP COPY: ", s3);

        // deep copy of john (move john's info)
        auto s4 = new Student({std::move(s->_id), std::move(s->_name)});
        print("DEEP COPY: ", s4);

        // remember to delete!!
        delete s;
        //delete s2; // !! DON'T TRY TO DELETE THE SHALLOW COPY!!!
        delete s3;
        delete s4;
    }
    std::cout << "--------" << std::endl;
    {
        auto sp1 = SmartPtr::make_smartptr();
        sp1->_id = "W222333";
        sp1->_name = "jane";
        print("ORIGINAL: ", sp1);

        // borrow a reference to the data (shallow copy)
        auto student = sp1.get();
        print("REFERENCED: ", student);

        // deep copy (leave original alone)
        auto sp2 = SmartPtr::make_smartptr();
        sp2->_id = sp1->_id;
        sp2->_name = sp1->_name;
        print("COPIED: ", sp2);

        // move ownership (move allocated memory)
        auto sp3 = std::move(sp1);
        print("MOVED: ", sp3);

        // CAN'T DO THIS! THE DATA HAS BEEN MOVED!!
//        auto sp4 = SmartPtr::make_smartptr();
//        sp4->_id = sp1->_id;
//        sp4->_name = sp1->_name;
//        print("COPIED: ", sp4);
    }
    std::cout << "--------" << std::endl;
    {
        // STL version
        auto up1 = std::make_unique<Student>();
        up1->_id = "W333444";
        up1->_name = "jill";
        print("UNIQUE: ", up1);

        // borrow a reference
        auto student = up1.get();
        print("REFERENCED: ", student);

        // deep copy
        auto up2 = std::make_unique<Student>(*up1);
        print("COPIED: ", up2);

        // give ownership
        auto up3 = std::move(up1);
        print("MOVED: ", up3);

        // deep copy (CAN'T! SINCE WE GAVE OWNERSHIP TO up3!!)
//        auto up4 = std::make_unique<Student>(*up1);
//        print("COPIED: ", up4);
    }

    return 0;
}