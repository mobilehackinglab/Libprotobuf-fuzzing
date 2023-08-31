#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person_data {
    unsigned long id;
    char name[64];
};

extern void add_person(struct person_data *new_person){
    char buf[64];
    memset(buf,0,sizeof(buf));
    unsigned int copied_size = 0;
    char *store_person_name = NULL;
    if(new_person->id > 100000 && new_person->id < 200000){
        for (size_t i = 0; i < sizeof(buf) - 1; i++)
        {
            if (new_person->name[i] == '\x00')
            {   
                if (i > 32)
                {
                    copied_size = i;
                    store_person_name = (char *)malloc(copied_size);
                    break;

                }else
                {
                    return;
                }
                
            }
            buf[i] = new_person->name[i];
            
        }
        if (store_person_name)
        {
            memcpy(store_person_name,buf,sizeof(buf));
        }
        

        
    }
}