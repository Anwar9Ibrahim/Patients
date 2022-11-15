#include<stdio.h> 
//File path variable
char* filePath = "\Patients.txt";
//Declaration of Linked list
struct linkNode {
    char* name;
    int id;
    char* date;
    char* insurance;
    char* insuranceCompany;
    char* departement;
    struct linkNode* next;
    struct linkNode* prev;
}*head, * tail;
typedef struct linkNode* link;
//function to insert element in the beginning of the Doubly linked list
void InsertAtBeginning(char* name, int id, char* date, char* insurance, char* insuranceCompany, char* departement)
{
    link temp;
    temp = (link)malloc(sizeof(struct linkNode));
    temp->name = name;
    temp->id = id;
    temp->date = date;
    temp->insurance = insurance;
    temp->insuranceCompany = insuranceCompany;
    temp->departement = departement;
    // list is empty
    if (head == NULL) {
        head = (temp);
        (head)->prev = NULL;
        (head)->next = NULL;
        tail = temp;
    }
    else {
        temp->prev = NULL;
        temp->next = head;
        (head)->prev = temp;
        head = temp;
    }
}
//create Doubly linked list
void CreateLinkedist()
{
    FILE* file = fopen(filePath, "r");
    //temporary variables to store each line variables
    char temp[50];
    char* _name = "";
    int _id = "";
    char* _date = "";
    char* _insurance = "";
    char* _insuranceCompany = "";
    char* _departement = "";
    link* _head; link* _tail;

    int i;
    int end;
    int start = 0;
    char line[150];//stor line
    int commaNum = 0;//to know the number of comma
    //if the file exist
    if (file != NULL) {

        while (fgets(line, sizeof(line), file))
        {
            for (i = 0; i < strlen(line); i++)
            {
                if (line[i] == ',' || i == strlen(line) - 1)
                {
                    end = i;
                    int c = 0;
                    int length;
                    if (commaNum == 0)
                        length = end - start;
                    else
                        length = end - start - 1;
                    int position = i - length;
                    while (c < length) {
                        temp[c] = line[position + c];
                        c++;
                    }
                    temp[c] = '\0'; //the id of the current line
                    switch (commaNum)// to fill the node with the value
                    {
                    case 0:
                    {
                        _name = strdup(temp);
                        break;
                    }
                    case 1: {
                        _id = atoi(temp);
                        break;
                    }
                    case 2:
                    {
                        _date = strdup(temp);
                        break;
                    }
                    case 3:
                    {

                        _insurance = strdup(temp);
                        break;
                    }
                    case 4:
                    {
                        _insuranceCompany = strdup(temp);
                        break;
                    }
                    case 5:
                    {
                        _departement = strdup(temp);
                        break;
                    }
                    default: break;

                    }

                    start = i;
                    commaNum = commaNum + 1;
                }

            }
            //After we get the variables we have insert node in the beginning  if the list
            InsertAtBeginning(_name, _id, _date, _insurance, _insuranceCompany, _departement);
            commaNum = 0;
            start = 0;
        }
        //close the file
        fclose(file);
    }
    else
        printf("The file dose not exist");

}
//function to delete by the id of the patients
void DeleteByid(char* id)
{
    link current = head;
    link before = head;
    while (current != NULL)
    {
        //if the patient is found
        if (current->id == id)
        {

            before->next = current->next;
            printf("Patient is deleted\n");
            break;
        }
        //else keep going
        else
        {
            before = current;
            current = current->next;
        }
    }
}
//function to show the patients
void View()
{
    //
    link current = head;
    while (current) {
        printf("Name: %s \n ", current->name);
        printf("id: %d \n", current->id);
        printf("Date: %s \n", current->date);
        printf("Insurance: %s \n", current->insurance);
        printf("Insuranceid: %s \n ", current->insuranceCompany);
        printf("Departement: %s \n", current->departement);
        printf("............................................. \n");
        current = current->next;
    }
}

//Declaration of Array Stack
struct stackNode {
    char* name;
    int id;
    char* date;
    char* insurance;
    char* insuranceCompany;
    char* department;
};
struct stackNode* stack; //pointer to the stack
int N; //number of elements in stack
int isEmpty() {
    return N == 0;
}
void push(char* name, int id, char* date, char* insurance, char* insuranceCompany, char* department)
{
    N++;
    stack[N].name = name;
    stack[N].id = id;
    stack[N].date = date;
    stack[N].insurance = insurance;
    stack[N].insuranceCompany = insuranceCompany;
    stack[N].department = department;
}
void CreateArrayStack()
{
    stack = malloc(50 * sizeof(int));
    FILE* file = fopen(filePath, "r");
    //temporary variables to store each line variables
    char temp[50];
    char* _name = "";
    int _id = "";
    char* _date = "";
    char* _insurance = "";
    char* _insuranceCompany = "";
    char* _departement = "";
  

     // Declaring FILE variable that will hold the file in order to read it.
    if (file != NULL)
    {
        int i;
        int end;
        int start = 0;
        char line[150];
        int commaNum = 0;
        //The process of reading the data out of the file is the same in the creating the linkedlist
        while (fgets(line, sizeof(line), file))
        {
            for (i = 0; i < strlen(line); i++)
            {
                if (line[i] == ',' || i == strlen(line) - 1)
                {
                    end = i;
                    int c = 0;
                    int length;
                    if (commaNum == 0)
                        length = end - start;
                    else
                        length = end - start - 1;
                    int position = i - length;
                    while (c < length) {
                        temp[c] = line[position + c];
                        c++;
                    }
                    temp[c] = '\0'; //the id of the current line
                    switch (commaNum)// to fill the node with the value
                    {
                    case 0:
                    {
                        _name = strdup(temp);
                        break;
                    }
                    case 1: {
                        _id = atoi(temp);
                        break;
                    }
                    case 2:
                    {
                        _date = strdup(temp);
                        break;
                    }
                    case 3:
                    {

                        _insurance = strdup(temp);
                        break;
                    }
                    case 4:
                    {
                        _insuranceCompany = strdup(temp);
                        break;
                    }
                    case 5:
                    {
                        _departement = strdup(temp);
                        break;
                    }
                    default: break;

                    }

                    start = i;
                    commaNum = commaNum + 1;
                }
            }
            push(_name, _id, _date, _insurance, _insuranceCompany, _departement);
            commaNum = 0;
            start = 0;
        }
        fclose(file);
    }
    else
    {
        printf("The file not exist\n");
    }
}

struct stackNode pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty");
        return;
    }
    else {
        // the node to be deleted
        struct stackNode node = stack[N];
        N = N - 1;
        return node;
    }

}
void ViewStack()
{
    int i;
    if (isEmpty()) {
        printf("Stack is empty \n");
        return;
    }
    for (i = N; i > 0; i--) {
        printf("Name: %s \n ", stack[i].name);
        printf("id: %d \n", stack[i].id);
        printf("Date: %s \n", stack[i].date);
        printf("Insurance: %s \n", stack[i].insurance);
        printf("Insuranceid: %s \n ", stack[i].insuranceCompany);
        printf("Departement: %s \n", stack[i].department);
        printf("............................................. \n");
    }
}



struct treeNode {
    char* name;
    int id;
    char* date;
    char* insurance;
    char* insuranceCompany;
    char* department;
    struct treeNode* left;
    struct treeNode* right;
};
struct treeNode* root;
struct treeNode* CreateNode(char* _name, int _id, char* _date, char* _insurance, char* _insuranceCompany, char* _department)
{
    struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    if (node == NULL)
    {
        fprintf(stderr, "Error!\n");
        exit(1);
    }
    node->name = _name;
    node->id = _id;
    node->date = _date;
    node->insurance = _insurance;
    node->insuranceCompany = _insuranceCompany;
    node->department = _department;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct treeNode* insertNode(char* _name, int _id, char* _date, char* _insurance, char* _insuranceCompany, char* _department)
{
    //if there is no nodes in the tree
    if (root == NULL)
    {
        root = CreateNode(_name, _id, _date, _insurance, _insuranceCompany, _department);
    }
    else
    {
        int is_left = 0;
        int r = 0;
        struct treeNode* cursor = root;
        struct treeNode* prev = NULL;
        //searching for the best place to insert the node
        while (cursor != NULL)
        {
            if (_id > cursor->id)
                r = 1;
            else if (_id < cursor->id)
                r = -1;
            else
                r = 0;
            prev = cursor;
            if (r < 0)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if (r > 0)
            {
                is_left = 0;
                cursor = cursor->right;
            }

        }
        if (is_left)
            prev->left = CreateNode(_name, _id, _date, _insurance, _insuranceCompany, _department);
        else
            prev->right = CreateNode(_name, _id, _date, _insurance, _insuranceCompany, _department);

    }
    return root;
}
createBST()
{
    FILE* file = fopen(filePath, "r");
    //temporary variables to store each line variables
    char temp[50];
    char* _name = "";
    char* _id = "";
    char* _date = "";
    char* _insurance = "";
    char* _insuranceCompany = "";
    char* _departement = "";
    /* link* _head; link* _tail;*/

     // Declaring FILE variable that will hold the file in order to read it.
    if (file != NULL)
    {
        int i;
        int end;
        int start = 0;
        char line[150];
        int commaNum = 0;
        //The process of reading the data out of the file is the same in the creating the linkedlist
        while (fgets(line, sizeof(line), file))
        {
            for (i = 0; i < strlen(line); i++)
            {
                if (line[i] == ',' || i == strlen(line) - 1)
                {
                    end = i;
                    int c = 0;
                    int length;
                    if (commaNum == 0)
                        length = end - start;
                    else
                        length = end - start - 1;
                    int position = i - length;
                    while (c < length) {
                        temp[c] = line[position + c];
                        c++;
                    }
                    temp[c] = '\0'; //the id of the current line
                    switch (commaNum)// to fill the node with the value
                    {
                    case 0:
                    {
                        _name = strdup(temp);
                        break;
                    }
                    case 1: {
                        _id = strdup(temp);
                        break;
                    }
                    case 2:
                    {
                        _date = strdup(temp);
                        break;
                    }
                    case 3:
                    {

                        _insurance = strdup(temp);
                        break;
                    }
                    case 4:
                    {
                        _insuranceCompany = strdup(temp);
                        break;
                    }
                    case 5:
                    {
                        _departement = strdup(temp);
                        break;
                    }
                    default: break;

                    }

                    start = i;
                    commaNum = commaNum + 1;
                }
            }
            insertNode(_name, _id, _date, _insurance, _insuranceCompany, _departement);
            commaNum = 0;
            start = 0;
        }
        fclose(file);
    }
    else
    {
        printf("The file not exist\n");
    }
}
void ViewInOrder(struct treeNode* current)
{
    if (current == NULL)
        return;
    else
    {
        ViewInOrder(current->left);	//Traverse left

        printf("Name: %s \n ", current->name);
        printf("id: %s \n", current->id);
        printf("Date: %s \n", current->date);
        printf("Insurance: %s \n", current->insurance);
        printf("Insuranceid: %s \n ", current->insuranceCompany);
        printf("Departement: %s \n", current->department);
        printf("............................................. \n");
        ViewInOrder(current->right); //Traverse right
    }
}
void ViewPreOrder(struct treeNode* current)
{
    if (current == NULL)
        return;
    else
    {
        printf("Name: %s \n ", current->name);
        printf("id: %s \n", current->id);
        printf("Date: %s \n", current->date);
        printf("Insurance: %s \n", current->insurance);
        printf("Insuranceid: %s \n ", current->insuranceCompany);
        printf("Departement: %s \n", current->department);
        printf("............................................. \n");
        ViewInOrder(current->left); //Traverse left
        ViewInOrder(current->right); //Traverse right
    }
}
void ViewPostOrder(struct treeNode* current)
{
    if (current == NULL)
        return;
    else
    {
        ViewInOrder(current->left); // Traverse left
        ViewInOrder(current->right); // Traverse right
        printf("Name: %s \n ", current->name);
        printf("id: %s \n", current->id);
        printf("Date: %s \n", current->date);
        printf("Insurance: %s \n", current->insurance);
        printf("Insuranceid: %s \n ", current->insuranceCompany);
        printf("Departement: %s \n", current->department);
        printf("............................................. \n");
    }
}


void main()
{

    int choice;
    int operation;
    int i;
    int idToDelete;

    printf("----------Welcom----------- \n");
    while (1)
    {

        //show the menu
        printf("Choose a number and get Details \n");
        printf(" 1 : Doubly linked list\n");
        printf(" 2 : Array stack\n");
        printf(" 3 : Binary search tree\n");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1: {
            CreateLinkedist();
            while (1) {
                printf("\n");
                printf("The Doubly linked list for Patients had been created  \n");
                printf("Choose a number and get the retult of your operation:\n");
               /* printf(" 1 : Create Linked list for Patients\n");*/
                printf(" 1 : Insert Patient\n");
                printf(" 2 : Delete Patient information by id\n");
                printf(" 3 : View all Patients \n");
                printf(" 4 : Back to main menu\n");
                scanf_s("%d", &operation);
                switch (operation)
                {

                case 1: {
                    printf("Please enter the name of the patient\n");
                    char currentName[20];
                    scanf("%s", currentName);
                    printf("Please enter the id of the patient\n");
                    char id[20];
                    scanf("%s", id);
                    printf("Please enter the  Date\n");
                    char date[30];
                    scanf("%s", date);
                    printf("Does the patient has insurance? \n");
                    printf("Press 1 for yes \n");
                    printf("Press 2 for no \n");
                    char* insurance;
                    char j[20];
                    scanf("%s", j);
                    if (j == "1")
                    {
                        insurance = "Yes";
                    }
                     else if (j =="2")
                    {
                        insurance = "No";
                    }
                    else
                    {
                        insurance = "Yes";
                        
                    }
                    printf("Please enter the name of the insurance company\n");
                    char company[20];
                    scanf("%s", company);
                    printf("Please enter the Department name \n");
                    char department[20];
                    scanf("%s", department);
                    InsertAtBeginning(currentName, atoi(id), date, insurance, company, department);
                    printf("the new item was pushed successfully! \n");

                    break;
                }
                case 2: {
                    
                    printf("Please Enter the Id of the patient you want to delete\n");
                    char temp[20];

                    scanf("%s",temp);
                    int IdToDelete = atoi(temp);
                    DeleteByid(IdToDelete);
                    printf("********************\n");
                    break;
                }
                case 3: {
                    printf(" You choose view \n");
                    View();
                    break;
                }
                case 4: {

                    break;
                }
                default:
                {
                    printf("Your input is not correct, Please try again \n");
                }
                }
                if (operation == 4)
                    break;
            }
            break;
        }
        case 2: {
            CreateArrayStack();
            while (1)
            {
                printf("The Array Stack for Patients had been created  \n");
                printf("Choose a number and get the retult of your operation:\n");             
                printf(" 1 : Push an patient\n");
                printf(" 2 : Pop the last patient\n");
                printf(" 3 : View all patients\n");
                printf(" 4 : Back to main menu\n");
                scanf_s("%d", &operation);
                switch (operation)
                {

                case 1: {
                    printf("Please enter the name of the patient\n");
                    char currentName[20];
                    scanf("%s", currentName);
                    printf("Please enter the id of the patient\n");
                    char id[20];
                    scanf("%s", id);
                    printf("Please enter the  Date\n");
                    char date[30];
                    scanf("%s", date);
                    printf("Does the patient has insurance? \n");
                    printf("Press 1 for yes \n");
                    printf("Press 2 for no \n");
                    char* insurance;
                    char j[20];
                    scanf("%s", j);
                    if (j == "1")
                    {
                        insurance = "Yes";
                    }
                    else if (j == "2")
                    {
                        insurance = "No";
                    }
                    else
                    {
                        insurance = "Yes";

                    }
                    printf("Please enter the name of the insurance company\n");
                    char company[20];
                    scanf("%s", company);
                    printf("Please enter the Department name \n");
                    char department[20];
                    scanf("%s", department);
                    push(currentName, atoi(id), date, insurance, company, department);
                    printf("the new item was pushed successfully! \n");

                    break;
                }
                case 2: {
                    printf("You choose to pop \n");
                    pop();
                    break;
                }
                case 3: {
                    printf("You choose to view \n");
                    ViewStack();
                    break;
                }
                case 4: {
                    break;
                }
                default:
                {
                    printf("Your input is not correct, Please try again \n");
                }
                }
                if (operation == 4)
                    break;
            }
            break;
        }
        case 3: {
            createBST();
            while (1)
            {
                printf("The Binary Search Tree for Patients had been created  \n");
                printf("Choose a number and get the retult of your operation:\n");              
                printf(" 1 : View InOrder all patients\n");
                printf(" 2 : View PreOrder all patients\n");
                printf(" 3 : View PostOrder all patients\n");
                printf(" 4 : Back to main menu\n");
                scanf_s("%d", &operation);
                switch (operation)
                {
 
                case 1: {
                    printf("You choose to View InOrder \n");
                    ViewInOrder(root);
                    break;
                }
                case 2: {
                    printf("You choose to View PreOrder \n");
                    ViewPreOrder(root);
                    break;
                }
                case 3: {
                    printf("You choose to View PostOrder \n");
                    ViewPostOrder(root);
                    break;
                }
                case 4: {
                    break;
                }
                default:
                    printf("Your input is not correct, Please try again \n");
                }
                if (operation == 4)
                    break;
            }
            break;
        }
        default:
        {
            printf("Your input is not correct\n");
            break;
        }
        



        }
    }

}
