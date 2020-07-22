#include "iostream"
#include "string"
#include "iomanip"
#include "fstream"
using namespace std;

/* 디렉토리 또는 파일에 대한 메인 class */
class node{
public:
    string name;
    node *child;
    node *peer;
    node *parent;
    enum type {file, directory};
    type type1;
    int fno;

    node()    //생성자
    {
        name = "";
        child = NULL;
        peer = NULL;
        parent = NULL;
        type1 = directory;
        fno = 0;
    }

    ~node(){};//소멸자
};



/* 프롬포트 기능을 하는 메소드를 담는 class */
class fileSystem
{
    string fsname;
    node *cwd;
    string prompt;
    static int fileno;

public:
    fileSystem()
    {
        fsname = "";
        cwd = new node;     //current working directory
        prompt = fsname;
    }
        
    void mkdir(string);
    int changedir(string);
    void ls();
    int del(string);
    int cut(string);
    int copy(string);
    int paste(string);
    int counter();
    void showprompt();
    void out();

};

int fileSystem::fileno = 0;


/* 파일 또는 폴더를 만드는 함수 */
void fileSystem::mkdir(string directory)
{
    node *exist = cwd->child;
    int cnt=0;
    while(exist != NULL){
        if(exist->name == directory){
            cnt++;  //만약 기존 폴더 및 파일을 반복하여 탐색했을 때 같은 이름을 갖고 있는 경우 cnt 증가
        }
        exist = exist->peer;    //원하는 파일 또는 폴더를 찾을 때까지 반복.
    }
    if(cnt == 0){
        /*새 노드 생성*/
        node *pointer = new node;
        pointer->name = directory;
        
        /* 새 노드를 디렉토리에 할당 */
        pointer->peer = cwd->child;
        cwd->child = pointer;
        
        pointer->parent = cwd;
        
        /*디렉토리로 타입 변경*/
        
        if(pointer->name.find('.') == string::npos) //이름에 .이 들어갈 경우 파일로 취급.
            pointer->type1 = pointer->directory;
        else
            pointer->type1 = pointer->file;
        
        /* 파일 넘버링 */
        pointer->fno = counter();
    }
    else{
        cout<<"Already Exist!"<<'\n';
        return ;
    }
    
}

// cd 입력을 통해 현재 상태의 위치를 바꾸는 함수
int fileSystem::changedir(string dir_to_change)
{
    /* 새 노드포인터를 만들고 cwd의 child를 가리킨다 */
    node *pointer = cwd->child;
    
    /*dir_to_change가 일치하는지 획인한다*/
    while (pointer != NULL)
    {
        if (pointer->name == dir_to_change && pointer->type1)
        {
            pointer->parent = cwd;
            cwd = pointer;
            /* 프롬포트에 다음과 같이 보여주도록한다 */
            prompt = prompt + "/" + cwd->name ;
            return 0;
        }
        pointer = pointer->peer;
    }
    cout<<endl<<"Invalid Directory name or It's a File";
    return 0;

}
// ls 입력을 통해 현재 상태의 내용을 보여주는 함수
void fileSystem::ls(){
    /* 현재 디렉토리의 파일 및 폴더들의 리스트를 보여준다 */
    node *pointer = cwd->child;

    while (pointer != NULL)
    {
        cout<<" "<<pointer->name<<endl;
        pointer = pointer->peer;
    }
}
// rm 입력을 통해 현재 위치의 내용을 삭제하는 함수
int fileSystem::del(string name_to_delete)
{
    node *pointer = cwd->child;
    node *previous = cwd->child;
 
    while (pointer != NULL)
    {
        if (pointer->name == name_to_delete)
        {
            if (previous->name == pointer->name)
                cwd->child = pointer->peer;
            else
                previous->peer = pointer->peer;
            delete pointer;            /* delete() 사용해 노드를 제거해준다 */
            return 0;
        }
        previous = pointer;
        pointer = pointer->peer;
    }

    cout<<endl<<"Invalid name";
    return 0;
}

node *copyDir = new node;   //노드를 복사하기 위한 임시변수

// cut 명령어를 통해 해당 파일 및 폴더는 삭제함과 동시에 copyDir 변수에 해당 내용을 저장(복사)해둔다.
int fileSystem::cut(string name_to_cut)
{
    node *pointer = cwd->child;
    node *previous = cwd->child;

    while (pointer != NULL)
    {
        if (pointer->name == name_to_cut)
        {
            
            if (previous->name == pointer->name)
                cwd->child = pointer->peer;
            else
                previous->peer = pointer->peer;
            
            previous = pointer;
            pointer = pointer->peer;
            copyDir = previous;
            cout<<"Copy: "<<copyDir->name<<'\n';
            delete pointer;
            return 0;
        }
        pointer = pointer->peer;    //원하는 파일 또는 폴더를 찾을 때까지 반복.
    }
 
    cout<<endl<<"Invalid name";
    return 0;
}

// copy 명령어를 통해 해당 파일 및 폴더를 copyDir에 복사해준다.
int fileSystem::copy(string name_to_copy)
{
    node *pointer = cwd->child;
    node *previous = cwd->child;

    while (pointer != NULL)
    {
        if (pointer->name == name_to_copy)
        {
            previous = pointer;
            pointer = pointer->peer;
            copyDir = previous;
            cout<<"Copy: "<<copyDir->name<<'\n';
            return 0;
        }
        pointer = pointer->peer;    //원하는 파일 또는 폴더를 찾을 때까지 반복.
    }

    cout<<endl<<"Invalid name";
    return 0;
}

// paste 명령어를 통해 copyDir의 변수를 원하는 위치에 붙여넣어 준다.
int fileSystem::paste(string directory)
{
    node *pointer = cwd->child;
    int cnt=0;
    /* 새 노드를 디렉토리에 할당 */
    if(copyDir == NULL){
        return 0;
    }
    else{
        while(pointer != NULL){
            if(pointer->name == copyDir->name){
                cnt++;  //만약 기존 폴더 및 파일을 반복하여 탐색했을 때 같은 이름을 갖고 있는 경우 cnt 증가
            }
            pointer = pointer->peer;    //원하는 파일 또는 폴더를 찾을 때까지 반복.
        }
        if(cnt == 0){   //cnt가 0이라는 것은 같은 이름을 가진 파일 및 폴더가 없음을 의미. 복사 진행
            copyDir->peer = cwd->child;
            cwd->child = copyDir;
            
            copyDir->parent = cwd;
            
            /*디렉토리로 타입 변경*/
            copyDir->type1 = copyDir->directory;
            
            /* 파일 넘버링 */
            copyDir->fno = counter();
            cout<<"Paste: "<<copyDir->name<<'\n';
        }
        else{
            cout<<"Already Exist!"<<'\n';
            return 0;
        }
    }
    
    return 0;
}


// cd.. 명령어를 통해 이전 디렉토리로 이동시켜준다.
void fileSystem::out()
{
        node *pointer = cwd->parent;

        if (cwd->parent == NULL)
        {
            return;
        }

    
        int namelength = (cwd->name).length();
        int n = prompt.find(cwd->name);
    
        prompt.erase(n-1, namelength+1);

        cwd = pointer;
}

int fileSystem::counter()
{
    fileno++;
    //increment the fileno each time an object is created and return
    return fileno;
}


void fileSystem::showprompt()
{
    cout<<endl<<prompt<<"/> ";

}


/* Command */
#define MKDIR 0
#define DIR 1
#define CD 2
#define DEL 3
#define CUT 4
#define COPY 5
#define PASTE 6
#define OUT 7
#define EXIT 8
#define INVALID -1

int parse_command(string *cmd)
{
    string command[9]= {"add", "ls", "cd", "rm", "cut","copy", "paste", "cd..",  "exit"};
    int c = 0;
    
    while (command[c] != *cmd)
    {
        c++;
        if(c>8)
            return -1;
    }
    
    return c;
}

int main()
{
    int commandno;  //특정 수에 의해 명령어가 작동한다.
    string command;  //전체 명령어를 입력한다.

    string *only_command = new string;
    char comd_array[12];  //명령어를 별도로 저장하는 경우.
    string input_name;    //cli로 요청된 명령내용
    int wlen, pos_of_space; //단어의 길이와, 스페이스바 위치
    fileSystem filesys;
    
    /*프롬포트를 보여주는 역할*/
    filesys.showprompt();

    while (1)
    {
        /* Get a command */
        getline (cin, command, '\n');
        wlen = command.length();  //명령어의 길이를 저장
        pos_of_space = command.find(' '); //스페이스바 입력 위치를 저장
        command.copy(comd_array, pos_of_space, 0);
        if (pos_of_space != string::npos)
        {
            comd_array[pos_of_space]=0;
            input_name = command.substr(pos_of_space+1, wlen);
        }
        else
            comd_array[wlen] = '\0';
        *only_command = comd_array;
        
        commandno = parse_command(only_command); //해당 명령어를 정수형태로 변환하여 불러온다

        switch (commandno)
        {
            case MKDIR:
                filesys.mkdir(input_name);
                break;
            
            case DIR:
                filesys.ls();
                break;

            case CD:
                filesys.changedir(input_name);
                break;

            case DEL:
                filesys.del(input_name);
                break;
            case CUT:
                filesys.cut(input_name);
                break;

            case COPY:
                filesys.copy(input_name);
                break;
            
            case PASTE:
                filesys.paste(input_name);
                break;
                
            case EXIT:
                return 0;
                break;
            
            case INVALID:
                cout<<"\nInvalid command\n";
                break;
            
            case OUT: //for cd..
                filesys.out();
                break;

            default:
                cout<<"Invalid command\n";
                break;
        }
        filesys.showprompt();
    }
    return 0;
}