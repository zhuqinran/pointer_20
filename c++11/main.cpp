#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<list>
#include<vector>
#include<stack>
#include<memory>//�ڴ� ����ָ��
#include<Initializer_List>
//#define NDEBUG //���ж���ʧЧ
//#include<assert.h>//����ͷ�ļ�
#include<algorithm>//�㷨
//�쳣 ���Ǵ���
void task38()
{
	vector <int> arr{ 1, 2, 3, 4, 5, 6 };
	//int arr[]={ 1, 2, 3, 4, 5, 6 };
	try
	{
		while (1)
		{
			system("pause");//�����������
			auto p = new int(1024 * 1024 * 25);//100MB
			cout << p << endl;
		}
	}
	catch (exception &d)//���쳣�����б�׼ C++ �쳣�ĸ��ࡣ
	{
		cout << "����������" << endl;
	}
	catch (bad_alloc &b)//��ʹ��new�����ڴ�ռ�ʱ���ڴ�ռ䲻��ʱ�ͻ��׳����쳣��
	{
		cout << b.what() << endl;
	}
	try
	{
		for (int i = 0; i < 7; i++)
		{
			cout << arr.at(i) << endl; // arr[0]������[]����� Ч�ʺ� ���ܺ� ��ȫ�Ե�	//arr.at(0);��ȫ�Ը�
		}
		throw 2;//�׳��쳣  ûtry catch �͹ر� �����������Ͷ���
		cout << "��ӡ����" << endl;
	}
	catch (int test)//�����쳣
	{
		cout << "�������쳣���쳣����" << test << endl;
	}
	catch (out_of_range &e)//����Խ���쳣 throw out_of_range("����Խ��");
	{
		cout << "����Խ���쳣" << endl;
	}
	//��������c++�쳣
	catch (...)
	{
		cout << "�������쳣" << endl;
	}
	cout << "�������һ��" << endl;
}
//struct Ĭ�����Գ�Ա���ǹ��е�
struct m
{
	int value;
};
//��װ:���г�Ա����˽�У��ⲿֻ��ͨ�����к��������� 
//��������  ��� ǳ���� ʲôʱ�򿽱�
//classĬ�����г�Ա˽��
//�������������� �����ȹ������
//delete ���ñ���������Ĭ��
//default �ñ���������Ĭ�ϵ�
class principal
{
	string name;
public:
	principal(string sname)
	{
		this->name = sname;
	}
	~principal()
	{
		cout << name << "�°���" << endl;
	}
	void wash()
	{
		cout << "ϴԡ" << endl;
	}
};
class A
{
public:
	A()
	{
		cout << "�޲ι���A" << endl;
	}
	A(const A &)
	{
		cout << "��������A" << endl;
	}

};
class school
{
	//private ˽�� ֻ�б���ʹ��
	//protected://�ܱ��� ���� �������� ���� ����ʹ��
public:
	string schoolName;//ѧУ��
	string schoolType;//ѧУ��� Сѧ ���� ���� ��ѧ
	string address;//ѧУ��ַ
	//���췽��  this ���Զ�����ȥһ����������Ϊ���г�Ա��������Ҫ��һ��thisָ��
	//school() = default;//Ĭ�ϵĹ��캯�������г�Ա���󣬵�����Ĭ�Ϲ��췽�� ==school(){}
	char *ptr;
	A test;
	principal *master;
	~school()//����
	{
		cout << schoolName << "��������" << endl;
		delete master;
	}
	//ǳ����
	school()
	{
		cout << "�޲ι���" << endl;
	}
	school(string schoolName, string schoolType, string address)
	{
		cout << "��ͨ���캯��" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("����ʦ");
	}
	//������һ��һ���� const ֻ�������޸�  ���
	school(const school &p) :schoolName(p.schoolName), schoolType(p.schoolType), address(p.address)//��ʼ�������б�
	{
		test = p.test;
		master = new principal(*p.master);
		cout << this->schoolName << "�����˿������캯��" << endl;
	}
	//��Ĭ�ϵ��ƶ������Ĭ�ϵĿ�������Ч��
	school(school &&other) :schoolType(other.schoolType), address(other.address), schoolName(other.schoolName)
	{
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}
	virtual void SchoolOpens()
	{
		cout << this->schoolName << "��ѧ��" << endl;
	}
	//�ݹ�������г�Ա����Ŀ������췽����������Ƕ��󣬾͸���
	//school(const school &p):schoolName(p.schoolName),schoolType(p.schoolType),address(p.address)//const ==ֻ��{}
};
void initSchool(school *_this, string schoolName, string schoolType, string address)
{
	_this->schoolName = schoolName;
	_this->schoolType = schoolType;
	_this->address = address;
}
void  swap(school A, school B)
{
	school tem = A;//school tem(A); ���ÿ�������
	//A = B;//��ֵ���� ���쿽��
	//B = tem;
}
void school_run(school *_this)
{
	cout << _this->schoolName << "��ѧ��" << endl;
}
void task39()
{
	// * s=(school*)malloc(sizeof(school));//c���Դ���school���� school��С�ռ�
	//initSchool(s, "����ָ��", "��ҵ��ѵ����", "����");
	//school_run(s);
	school *s2 = new school("ָ��", "��ҵ��ѵ����", "����");
	s2->SchoolOpens();
	system("pause");
	delete s2;
	system("pause");
}
void run()
{
	school s1("ָ��", "��ҵ��ѵ����", "����");
	school s2("����ָ��", "��ҵ��ѵ����", "����");
	swap(s1, s2);
}
//���������Ż�
school getschool()
{
	school s2("ָ��", "��ҵ��ѵ����", "����");//�ṹ��
	return school(s2);
}
//�ƶ�����
void task40()
{
	school s1(getschool());
	s1.schoolName = "��һũ��";
	school s2("ָ��", "��ҵ��ѵ����", "����");
	school s3(std::move(s2));//�ƶ�����
}
typedef int I;
using I = int;
//��������������void ���ܲ�����int const std::string&,���ֲ�ͬ�﷨��д����ͬ
typedef void(*FP)(int, const std::string&); //using FP=void (*)(int,const std::string&);
void task41()
{
	int x1 = 5;
	int x2 = 12;
	swap(x1, x2);
	run();
	cout << "��һ�����" << endl;
}
//��ֵ����ֵ������ֵ���ú���ֵ����
//������ ָ��������һ�� school &r1=*s1 r1.master==(*s1)master;
void task42()
{
	int *p = nullptr;//��ָ��  
	int &r = *(int *)(nullptr);//int����
}
//��Ԫ
class C
{
public:
	C(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
	void Getxy();
	friend double Distance(C &a, C &b);
private:
	double x, y;
};
void C::Getxy()
{
	cout << "(" << x << "," << y << ")" << endl;
}
double Distance(C &a, C &b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
void task43()
{
	C p1(3.0, 4.0);
	C p2(6.0, 8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1, p2);
	cout << "Distance is" << " " << d << endl;
}
//���������
class complex
{
	int real;
	int imagin;
public:
	complex(int x, int y) :real(x), imagin(y)
	{

	}
	complex operator+(complex & x)
	{
		return complex(real + x.real, imagin + x.imagin);
	}
	complex operator-(complex & x)
	{
		return complex(real - x.real, imagin - x.imagin);
	}
	string toString()
	{
		char buff[50];
		sprintf(buff, "(%d+%di)", real, imagin);
		return string(buff);
	}
};
ostream & operator<<(ostream &o, complex &c)
{
	o << c.toString();
	return o;
}
void task44()
{
	complex a(2, 3);
	complex b(6, 2);
	cout << a << "��" << b << "��" << (a + b).toString() << endl;
	//������ֵ
	a.operator-(b);
}
//�̳лὫ���г�Ա�̳� ���� ����
class University :public school
{
public:
	principal *Vice;//��У��
	University() :school("ָ��", "��ҵ��ѵ����", "����")//�����б�
	{
		cout << "��ѧ�Ĺ���" << endl;
	}
	//�麯�� ��д����  ������ͬ����ֵ��ͬ ������д����
	virtual void SchoolOpens()
	{
		cout << "��ѧУ��ѧ��" << endl;
	}
	~University()
	{
		cout << "�����˸�ѧУ����" << endl;
		delete Vice;
	}
};
//��̬˼�� ���Ը���ʵ�����ȥ��չ���� ��̬������ָ��ָ���������������෽��
//��д�麯�� ����ʵ�ֶ�̬
//������������Ϊ�˽��:��ɾ��ָ���������Ļ���ָ��ʱ���Ե�����������������ﵽ�ͷ������ж��ڴ��Ŀ�Ķ���ֹ�ڴ�й©��
void printfSchool(school * school)
{
	school->SchoolOpens();
	delete school;
}
void printfSchool(school & school)
{
	school.SchoolOpens();
	delete &school;
}
void task45()
{
	University u;
	school* s = &u;//school &s1 = u;
	s->SchoolOpens();
	printfSchool(&u);
}
//���麯��:����ӿ� java:interface 
//�����
//��ָ��:��ָ��ָ������Ӧ���麯����
//�麯����:�洢�������麯���ĺ���ָ��
//�麯��:�������麯�����࣬�ͻ���һ����ָ�� �麯��������д
//���ú���ʱ�����ֺ�������ͨ�������ܼ� ֱ�ӵ���
//���ú���ʱ�����ֺ������麯����ͨ����ָ���ҵ���Ӧ����ȥ����
class Nataorium
{
public:
	virtual void  wash() = 0;//���麯��  �����
};
vector<Nataorium*>allWash;
class A1
{
public:
	virtual void fun()
	{
		cout << "A1��fun" << endl;
	}
	virtual void druck()
	{
		cout << "A1��druck" << endl;
	}
	void eat()
	{
		cout << "A1��eat" << endl;
	}
};
class B :public A1
{
public:
	virtual void fun()
	{
		cout << "B��fun" << endl;
	}
	void eat()
	{
		cout << "B��eat" << endl;
	}
	virtual void druck()
	{
		cout << "B��druck" << endl;
	}
};
void show(A1 *p)
{
	p->druck();
	p->fun();
	p->eat();//eat�����麯��
}
void task46()
{
	A1 a;
	B b;
	a.druck();
	A1 *pb = &b;
	pb->druck();
	pb->fun();
	cout << "==========================================" << endl;
	show(&a);
	cout << "==========================================" << endl;
	show(&b);
}
//��ʼ���б�
//#define Lassert(t) (/(t))
class vec
{
	int *obj;
	vector<int>arr;
public:
	vec(initializer_list<int> arr)//��ʼ���б�
	{
		obj = new int[arr.size()];
		//����
		for (auto i = 0; i < arr.size(); i++)
		{
			obj[i] = *(arr.begin() + i);
		}
		for (auto i = arr.begin(); i != arr.end(); i++)
		{
			cout << *i << endl;
		}
	}
	int& operator[](unsigned int index)
	{
		//assert(index >= 0 && index <arr.size());//���� Ϊ1���� Ϊ0�˳�
		//Lassert(index>=0&&index<<arr.size());
		return obj[index];
	}
};
void task47()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, };
	vec v = { 1, 2, 3, 4, 5, 6, 7, };//initializer_list<int> �ܽ����������Ͳ��� �� vec v({ 1, 2, 3, 4, 5, 6, 7, });
	cout << v[2] << endl;
	v[2] = 5;
	cout << v[2] << endl;
	//vec tem{ 1, 2, 3 } = vec tem(1, 2, 3); //��ʼ�������б�
}
//Ĭ�Ϲ��캯��
class tool
{
public:
	int value;
	tool()
	{
		cout << "tool������" << endl;
	}
	tool(int t)
	{
		cout << "������������" << t << endl;
	}
	tool(const tool &)
	{
		cout << "tool����������" << endl;
	}
	tool(tool &&)
	{
		cout << "tool�ƶ�������" << endl;
	}
	~tool()
	{
		cout << "tool������" << endl;
	}
	tool& operator=(tool &&)
	{
		cout << "tool �ƶ���ֵ��" << endl;
		return *this;//*this��ǰ����
	}
	tool& operator=(const tool &)
	{
		cout << "tool ������ֵ��" << endl;
		return *this;
	}

};
class base
{
	virtual void run(){}
	//virtual void run()const {} //ֻ�������޸�
	//virtual void run() final{} //�޷���д  class base final ��base �಻�ܱ��̳�
};
class S1 :public base
{
	tool t = 2;
	int numb = 5;
public:
	void run() override {}//��д ����
	S1() :t(5){}//��ʼ���б�
	//delete ���ñ���������Ĭ�ϵ�
	//default �ñ���������Ĭ�ϵ�
	//S1()=delete;
	//S1()=default;
};
void task48()
{
	S1 s;
}
//��ָ��nullptr
void f(int t)
{
	cout << "int���غ���" << endl;
}
void f(char *p)
{
	cout << "ָ�����غ���" << endl;
}
void task49()
{
	f(nullptr);//��ָ��
	f(1);
}
//����ڴ� С���ڴ�
void task50()
{
	int a;
	unsigned char *p = (unsigned char *)&a;//(int(p)+sizeof(char*)*n)
	a = 10;
	printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
	a = 255;
	printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
	a = 256;
	printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
	a = 65536;
	printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
	//����ڴ��� 
	//0  0  0  10   һ���ֽ�8λ
	//0  0  0  255/1111 1111
	//0  0  1  0    = 256/1 0000 0000
	//0  1  0  0    =65536/1 0000 0000 0000 0000
	//С���ڴ���  internet����Ч�ʸ� �͵���λ
	//10  0   0   0
	//255 0   0   0
	//0   1   0   0
	//0   0   1   0
}
//��ģ�� ����ģ��
int Lmax(int a, int b)
{
	return a > b ? a : b;
}
double Lmax(double a, double b)
{
	return a > b ? a : b;
}
template <class T> T Lmax(T a, T b)//template <typename T> T Lmax(T a, T b)
{
	return a > b ? a : b;
}
template <int d, class T, class T1> T Lmax(T a, T1 b)
{
	cout << "ģ���Ƶ�����" << endl;
	return a > b ? a : b;
}
void task51()
{
	int x1 = 2, x2 = 5;
	double d1 = 2.3, d2 = 4.4;
	//��ʽ�Ƶ�
	cout << Lmax(x1, x2) << endl;
	cout << Lmax(d1, d2) << endl;
	//��ʾ�Ƶ�
	cout << Lmax<double>(x1, d1) << endl;
	cout << Lmax<2, int, double>(x1, d1) << endl;
	//��ʾָ��ģ�壬����ʹ��ģ���Ƶ��ĺ���������ʹ�÷�ģ��ĺ���
	cout << Lmax<2>(d1, d2) << endl;
}
template<class T>void Lswap(T& a, T& b)
{
	T tem = a;
	a = b;
	b = tem;
}
class A3
{
public:
	int value = 0;
	char *p;
	tool * t;
	A3(int v)
	{
		p = new char[100];
		t = new tool;
		value = v;
		cout << "���캯��" << endl;
	}
	//����ĳһ������
	operator int()
	{
		cout << "A3ת��Ϊint" << endl;
		return value;
	}
	operator double()
	{
		cout << "A3ת��Ϊdouble" << endl;
		return value;
	}
	//���Ƹ�ֵ�����
	A3 & operator=(const A3 & other)
	{
		delete p;
		delete t;
		p = new char[100];
		t = new tool;
		value = other.value;
		cout << "���Ƹ�ֵA3" << endl;
		return *this;
	}
	//�ƶ���ֵ�����
	A3 & operator=(A3 && other)
	{
		p = new char[100];
		t = other.t;
		other.t = nullptr;
		value = other.value;
		cout << "�ƶ���ֵA3" << endl;
		return *this;
	}
	A3(const A3& other) : A3(other.value)
	{
		cout << "��������" << endl;
	}
	~A3()
	{
		cout << "��������" << endl;
		delete p;
	}
	A3(A3 &&other)
	{
		t = other.t;
		other.t = nullptr;
		value = other.value;
		cout << "�ƶ�����A3" << endl;
	}
};
void Lswap(A &a, A & b)
{
	//tem ���Լ���p a�����Լ���p b���Լ���p
	A tem = a;//���
	//�ƶ����� A tem(std::move(a));
	//���Ƹ�ֵ���� a����b��p
	a.operator=(b);//ǳ����
	//�ƶ���ֵ a.operator=(std::move(b));
	//b����tem��p
	b.operator=(tem);
	//�ƶ���ֵ b.operator=(std::move(tem));
}
void task52()
{
	int x1 = 2, x2 = 5;
	double d1 = 2.3, d2 = 4.4;
	A3 a1(25);
	A3 a2(31);
	int d = a1.operator int();
	Lswap(a1, a2);
	Lswap(x1, x2);
	Lswap(d1, d2);
	cout << a1.value << " " << "�Զ������ͽ�������" << "  " << a2.value << endl;
	cout << x1 << " " << "int���ͽ�������" << " " << x2 << endl;
	cout << d1 << " " << "double���ͽ�������" << " " << d2 << endl;
}
//ģ���� ջ ������ 
template<class T>class L_stack
{
	T a;
	vector<T>arr;
public:
	void push(T &&obj)
	{
		arr.push_back(obj);
	}
	void pop()
	{
		arr.pop_back();
	}
	T & top()
	{
		return arr.back();
	}
	//��ʾ��Сsize_t
	size_t size()
	{
		return arr.size();
	}
	bool empty()
	{
		return arr.empty();
	}
};
//ģ������� ���
//print �Ĺ��� ���������Ĳ�����ȫ�������Ļ��
void run3(int){}
void Lprint()
{
	cout << "�ݹ����ս�" << endl;
}
template<class firstArgs, class...args>void Lprint(firstArgs f, args...d)
{
	cout << f << endl;
	//run3(d...);
	Lprint(d...);//�ݹ���
}
void task53()
{
	Lprint(1, 3.0, 5, "123");
	L_stack<int> l;
	l.push(5);
	l.push(6);
	l.push(7);
	cout << l.top() << endl;
	l.pop();
	cout << l.top() << endl;
	cout << l.size() << endl;
}
//����ָ�� ����ָ�� һ�ֶ����ܹ�����һ�������ͷ�
//���� �ռ�� �ɳ���Ա���� delete new 
//ջ�� �洢���ú����Ĺ�����Ҫ������  ϵͳ�Զ�����
//������  �洢���Դ���  ֻ�� �����޸�
//������   ���г��� �������޸�
//��̬��  ���о�̬��Ա������� �����޸� ����ɾ��  �Ǿ�̬ȫ�ֱ���Ҳ��ž�̬��  ��̬ȫ�ֱ��� ��̬�ֲ����� ȫ�ֱ���  
//�����������ڴ� ���ж�Ӧ��ַ
//ģ�廯�����Խ�����������
//���췽������ֵһ��ָ��
//�����������ͷ�ָ��
//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ��
//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ��Ŀ���Ȩ��
//reset �ͷ�֮ǰ�� ����µ�ָ��
// release���� �ͷſ���Ȩ������ָ��
//operator*() ģ��ָ����ʷ���
//operatpr->() ģ��ָ���ͷ���ʷ���
//get���� ���ָ��ָ���ָ��
template<class T>
class L_autoPtr
{
	T *obj = nullptr;
public:
	L_autoPtr(T *ptr) :obj(ptr){}
	L_autoPtr() = default;
	~L_autoPtr()
	{
		delete obj;
	}
	L_autoPtr(L_autoPtr<T>& ptr) :obj(ptr.release()){}
	L_autoPtr & operator=(L_autoPtr<T>& ptr)
	{
		obj = ptr.release();
		return *this;
	}
	void reset(T * newPtr = nullptr)
	{
		delete obj;
		obj = newPtr;
	}
	T * release()
	{
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T & operator*()
	{
		return *obj;
	}
	T * operator->()
	{
		return obj;
	}
	T * get()
	{
		return obj;
	}
};
void run4()
{
	auto_ptr<tool> ptr(new tool);
	auto_ptr<tool> ptr2(ptr);//ptr2����
	auto_ptr<tool> ptr3;
	L_autoPtr<tool> ptr4(new tool);
	L_autoPtr<tool> ptr5(ptr4);
	L_autoPtr<tool> ptr6;
	ptr3 = ptr2;//ptr3�ж��� ptr ptr2��
	cout << (*ptr5).value << endl;
	cout << ptr5->value << endl;
	ptr5.reset();//���ٱ��������
}
void task54()
{
	char *p = "123456";//p���ջ�� 123456��ų�����
	//T * t = new T();//T��Ŷ��� t���ջ��
	run4();
}
void main()
{
	//task38();//�쳣����
	//task39();//�������� ��� ǳ����
	//task40();//�ƶ�����
	//task41();//���������
	//task42();//ָ��������  ��ָ�� ��C++�У�NULLȴ����ȷ����Ϊ������0(int):
	//task43();//��Ԫ
	//task44();//���������
	//task45();//�̳�
	//task46();//��ָ��
	//task47();//��ʼ���б� ���� ������
	//task48();//Ĭ�Ϲ��캯��
	//task49();//��ָ��  ��C++�У�NULLȴ����ȷ����Ϊ������0��int��:
	//task50();//����ڴ� С���ڴ�
	//task51();//ģ�庯���Ƚϴ�С
	//task52();//ģ�庯������
	//task53();//ģ����[ ջ ������] ģ������� ���
	task54();//����ָ��
}