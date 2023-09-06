#include "/usr/local/include/libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "person_data.pb.h"

struct person_data {
    unsigned long id;
    char name[64];
};

void add_person(struct person_data *new_person);

DEFINE_PROTO_FUZZER(const person_data_fuzz &input){
    struct person_data real_input;
    memset(&real_input,0,sizeof(struct person_data));

    real_input.id = input.fuzz_id();

    unsigned int size = input.fuzz_name().length();
    const char *data = input.fuzz_name().data();

    if (size > sizeof(real_input.name))
    {
        memcpy(real_input.name,data,sizeof(real_input.name));
    }
    else
    {
        memcpy(real_input.name,data,size);
    }
    
    
    add_person(&real_input);
    

}

