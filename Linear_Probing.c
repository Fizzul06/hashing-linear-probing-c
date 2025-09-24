#include <stdio.h>
#include <stdbool.h>

#define SIZE 12
int hashTable[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void Insert(int key)
{
    int index = hash(key);

    bool slot_available = false;

    for (int i=0; i<SIZE; i++)
    {
        int theIndex = (index + i) % SIZE;
        if (hashTable[theIndex] == -1 || hashTable[theIndex] == -2)
        {
            slot_available = true;
            hashTable[theIndex] = key;
            break;
        }
    }

    if (slot_available == false)
    {
        printf("Insertion Fail: no slot available");
    }else
    {
        printf("Insertion success");
    }

}

int Search(int key)
{
    int index = hash(key);
    bool found = false;
    int keyIndex;

    for (int i=0; i<SIZE; i++)
    {
        int theIndex = (index + i) % SIZE;
        if (hashTable[theIndex] == -1)
        {
            break;
        }
        if (hashTable[theIndex] == key)
        {
            found = true;
            keyIndex = theIndex;
            break;
        }
    }

    if (found)
    {
        return keyIndex;
    }
    else
    {
        return -1;
    }

}

void Delete(int key)
{
    int index = Search(key);

    if (index != -1)
    {
        hashTable[index] = -2;
        printf("Key %d position at index %d was deleted", key, index);
    }
    else
    {
        printf("%d doesn't exist in the table");
    }
}

int main()
{
    // initialize it -1 mean empty
    for (int i=0; i<SIZE; i++)
    {
        hashTable[i] = -1;
    }

    bool in_operation = true;
    do
    {
        int input;
        printf("1.Enter key\n2.Search key\n3.Delete key\n4.Print Table\n5.Exit");
        printf("\nPick an option: ");
        scanf("%d",&input);

        if (input == 1)
        {
            int user_inputs;
            printf("\nEnter key to hash table: ");
            scanf("%d", &user_inputs);
            Insert(user_inputs);
        }
        else if (input == 2)
        {
            int user_inputs;
            printf("\nEnter key to search in the table: ");
            scanf("%d", &user_inputs);
            int result = Search(user_inputs);
            if (result != -1)
            {
                printf("The value %d found at index %d", user_inputs, result);
            }else
            {
                printf("The value %d doesn't exist in the table", user_inputs);
            }
        }
        else if (input == 3)
        {
            int user_inputs;
            printf("\nEnter a key to delete from the table: ");
            scanf("%d", &user_inputs);
            Delete(user_inputs);
        }
        else if (input == 4)
        {
            for (int i = 0; i<SIZE; i++)
            {
                if (hashTable[i] == -1)
                {
                    printf("\nIndex %d: Empty",i);
                }
                else if(hashTable[i] == -2)
                {
                    printf("\nIndex %d: Deleted",i);
                }
                else
                {
                    printf("\nIndex %d: %d",i,hashTable[i]);
                }
            }
        }
        else if (input == 5)
        {
            in_operation = false;
        }
        else
        {
            printf("Invalid input");
        }

        printf("\n\n\n");
    }while(in_operation);

    return 0;
}
