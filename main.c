/* Name:Nagashree N
Date:27-02-26
Progect name:Inverted Search Project
Description:The Inverted Search Project is a text-based search engine application designed to efficiently retrieve documents containing a specific word or phrase using an inverted index data structure. Instead of scanning every document for each search query, the system preprocesses the data and creates a structured index that maps each unique word to the list of documents in which it appears, along with the frequency of occurrences. The application reads multiple text files, extracts and normalizes words, and stores them using efficient data structures such as hash tables or dictionaries to enable fast lookups. When a user enters a search term, the system quickly accesses the inverted index and displays the relevant files and occurrence counts without reprocessing the documents. This project demonstrates key concepts in data structures, file handling, and string processing, while highlighting how search engines and document retrieval systems optimize performance for quick and accurate information retrieval.
The project involves reading multiple text files, performing word tokenization, removing unnecessary characters, and converting text into a standardized format to ensure accurate indexing. Efficient data structures such as hash tables, dictionaries, or linked lists are used to store and manage the indexed data. The system supports quick keyword-based searches, displaying relevant file names and word frequencies instantly without re-reading the files.

Additionally, the project emphasizes core concepts such as file handling, dynamic memory management, string manipulation, and algorithm optimization. It can be further enhanced by adding features like phrase search, stop-word removal, ranking results based on frequency, or implementing a user-friendly interface. Overall, the Inverted Search Project demonstrates how modern search engines and document retrieval systems organize and access large volumes of textual data in a fast, structured, and scalable manner.*/


#include "inverter.h"

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        printf(BOLD_RED "ERROR : Invalid command line arguments\n" RESET);
        return 0;
    }
    FILE_NAME* head = NULL;
    /*arguments validation*/
    for(int i=1;i<argc;i++)
    {
        if(validate_arguments(argv[i],&head)==1)
        {
            insert_at_last(argv[i],&head);
        }
    }
    /*printing the file names which are validated*/
    print_filename(head);
    /*creating hash of 26 alphabets and 1 for special characters*/
    hash_t arr[27];
    /*updating index value and link part*/
    for(int i=0;i<27;i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
    int create_flag = 0,update_flag = 0;
    while(1)
    {
        int opt;
        printf("----------------------------------------------------------------------------\n");
        printf(BLUE "\t\t\t::::::Menu::::::\n");
        printf("1.Create database \n2.Display database \n3.Save database \n4.Search database \n5.Update database\n6.Exit\n" RESET);
        printf("-----------------------------------------------------------------------------\n");
        printf("Enter the option : " );
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                /*creating the database*/
                if(create_flag == 1 || update_flag == 1)
                {
                    printf(BOLD_RED "ERROR : Create/Update already completed in this execution\n\n" RESET);
                }
                else
                {
                    create(arr,head);
                    create_flag = 1;
                    printf(BOLD_GREEN "Creating database is completed\n\n" RESET);
                }
                break;

            case 2:
                /*for Display the database*/
                display(arr);
                break;
            
            case 3:
                /*saving the database into one file*/
                save(arr);
                break;
            
            case 4:
                /*for searching the word in database*/
                search(arr);
                break;
            
            case 5:
                /*updating the database from backup file*/
                if(create_flag == 1 || update_flag == 1)
                {
                    printf(BOLD_RED "ERROR : Create/Update already completed in this execution\n\n" RESET);
                }
                else
                {
                    if(update(arr,head))
                    {
                        create(arr,head);
                        update_flag = 1;
                    }
                }
                break;

            case 6:
                /*destroying the created memories*/
                destroy_hash(arr);
                return 0;
                break;

            default:
                /*destroying the created memories*/
                destroy_hash(arr);
                return 0;
                break;
        }
        /*for continuous operations1*/
        printf("Do you want to continue ? (1.yes)(2.No) :");
        scanf("%d",&opt);
        if(opt == 2)
            break;
    }
    return 0;
}