#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

class BigInt{

	static const int MAX = 10000;
	std::map<int, std::string> ten;
	friend std::ostream& operator<<(std::ostream &, const BigInt &);
	friend std::istream& operator>>(std::istream &, BigInt &);

public:
	enum  sign{ POS = 0, NEG };
	BigInt(void);
	explicit BigInt(const std::string & );
	BigInt(const long long & );
	BigInt(const BigInt &);

	bool operator==(const BigInt &) const;
	bool operator==(const long long &) const;
	bool operator!=(const BigInt &) const;
	bool operator!=(const long long &) const;
	bool operator>(const BigInt &) const;
	bool operator>(const long long &) const;
	bool operator<(const BigInt &) const;
	bool operator<(const long long &) const;
	bool operator>=(const BigInt &) const;
	bool operator>=(const long long &) const;
	bool operator<=(const BigInt &) const;
	bool operator<=(const long long &)const;
	const BigInt& operator=(const BigInt &);
	const BigInt& operator=(const long long &);
	const BigInt operator-(const BigInt &);
	const BigInt operator-(const long long &);
	const BigInt operator+(const BigInt &);
	const BigInt operator+(const long long &);
	BigInt& operator+=(const BigInt &);
	BigInt& operator+=(const long long &);
	BigInt& operator-=(const BigInt &);
	BigInt& operator-=(const long long &);
	const BigInt operator*(const BigInt &) const;
	const BigInt operator*(const long long &) const;
	const BigInt operator/(const BigInt &);
	const BigInt operator/(const long long &);
	const BigInt operator%(const BigInt &);
	const BigInt operator%(const long long &);
	BigInt& operator*=(const BigInt &);
	BigInt& operator*=(const long long &);
	BigInt& operator/=(const BigInt &);
	BigInt& operator/=(const long long &);
	BigInt& operator%=(const BigInt &);
	BigInt& operator%=(const long long &);
	BigInt& operator++();
	BigInt& operator--();
	const size_t get_size() const;

private:
	std::array<int, MAX> num;
	sign status;
	void set_num(const std::string &);
	void set_num(const long long &);
	const std::array<int,MAX>& get_num() const;
	sign get_status() const;
	void clear();
	const BigInt inc(const BigInt&, const BigInt&);
	const BigInt dec(const BigInt&, const BigInt&);
	std::string toString(const BigInt &);
	const BigInt power(const long long &, const long long &);
	const BigInt div2(const BigInt &);
	void tens();
	const int safe = 800;
};
BigInt::BigInt(void){
	set_num("0");
}

BigInt::BigInt(const string &number){
	set_num(number);
}

BigInt::BigInt(const long long &number){
	set_num(number);
}

BigInt::BigInt(const BigInt &num2){
	//set_num(toString(num2));
	(*this).num = num2.num;
	(*this).status = num2.status;
}

string BigInt::toString(const BigInt &number){
	string s = "";
	int n = number.get_size();
	for (int i = 0; i < n; ++i){
		s += char('0' + number.num[i]);
	}
	return s;
}

void BigInt::set_num(const string &number){
	(*this).clear();
	size_t n = number.size();
	if (n > safe)
		throw invalid_argument("the number of digits must be <= 40");
	string s;
	if ('+' == number[0]){
		status = POS;
		s = number.substr(1);
	}
	else if ('-' != number[0])
	{
		status = POS;
		s = number;
	}
	else{
		status = NEG;
		s = number.substr(1);
	}
	reverse(s.begin(), s.end());
	int sz = s.size();
	for (int i = 0; i < sz; ++i){
		num[i] = s[i] - '0';
	}
}

void BigInt::set_num(const long long &number){
	string s = to_string(number);
	set_num(s);
}

bool BigInt::operator==(const BigInt &number) const{
	size_t n1 = get_size();
	size_t n2 = number.get_size();
	if (n1 != n2)
		return false;
	if (status != number.status)
		return false;
	for (size_t i = 0; i < n1; ++i){
		if (num[i] != number.num[i])
			return false;
	}
	return true;
}

bool BigInt::operator==(const long long &number) const{
	string s = to_string(number);
	BigInt temp(s);
	return (*this == temp);
}

bool BigInt::operator!=(const BigInt &number) const{
	size_t n1 = get_size();
	size_t n2 = number.get_size();
	if (n1 != n2)
		return true;
	if (status != number.status)
		return true;
	for (size_t i = 0; i < n1; ++i){
		if (num[i] != number.num[i])
			return true;
	}
	return false;
}

bool BigInt::operator!=(const long long &number) const{
	string s = to_string(number);
	BigInt temp(s);
	return (*this != temp);
}

bool BigInt::operator<(const BigInt &number) const{
	size_t n1 = get_size();
	size_t n2 = number.get_size();
	if (status != number.status)
	{
		if (NEG == status)
			return true;
		else if (NEG == number.status)
			return false;
	}
	if (n1 != n2){
		if (n1 > n2)
			return false;
		else if (n1 < n2)
			return true;
	}
	if (POS == status){
		for (int i = n1 - 1; i >= 0; --i){
			if (num[i] < number.num[i])
				return true;
			else if (num[i] > number.num[i])
				return false;
		}
		return false;
	}
	else{
		for (int i = n1 - 1; i >= 0; --i){
			if (num[i] > number.num[i])
				return true;
			else if (num[i] < number.num[i])
				return false;
		}
		return false;
	}
}

bool BigInt::operator<(const long long &number) const{
	string s = to_string(number);
	BigInt temp(s);
	return (*this < temp);
}

bool BigInt::operator>(const BigInt &number) const{
	size_t n1 = (*this).get_size();
	size_t n2 = number.get_size();
	if (status != number.status)
	{
		if (POS == status)
			return true;
		else if (POS == number.status)
			return false;
	}
	if (n1 != n2){
		if (n1 < n2)
			return false;
		else
			return true;
	}
	if (POS == status){
		for (int i = n1 - 1; i >= 0; --i){
			if (num[i] > number.num[i])
				return true;
			else if (num[i] < number.num[i])
				return false;
		}
		return false;
	}
	else{
		for (int i = n1 - 1; i >= 0; --i){
			if (num[i] < number.num[i])
				return true;
			else if (num[i] > number.num[i])
				return false;
		}
		return false;
	}
}

bool BigInt::operator>(const long long &number) const{
	string s = to_string(number);
	BigInt temp(s);
	return (*this > temp);
}

bool BigInt::operator>=(const BigInt &number) const{
	return (*this > number || *this == number);
}

bool BigInt::operator>=(const long long &number) const{
	return (*this > number || *this == number);
}

bool BigInt::operator<=(const BigInt &number) const{
	return (*this < number || *this == number);
}

bool BigInt::operator<=(const long long &number) const{
	return (*this < number || *this == number);
}

const BigInt& BigInt::operator=(const BigInt &number){
	clear();
	status = number.get_status();
	size_t n = number.get_size();
	for (size_t i = 0; i < n; ++i){
		num[i] = number.num[i];
	}
	return *this;
}

const BigInt& BigInt::operator=(const long long &number){
	string s = to_string(number);
	BigInt temp(s);
	*this = temp;
	return *this;
}

const BigInt BigInt::operator-(const BigInt &number){
	BigInt temp("0");
	if (*this == number){
		temp.status = POS;
	}
	else if (status == POS && number.status == POS){
		temp = dec(*this, number);
	}
	else if (POS == status && NEG == number.status){
		temp = inc(*this , number);
		temp.status = POS;
	}
	else if (NEG == status && POS == number.status){
		temp = inc(*this , number);
		temp.status = NEG;
	}
	else if (NEG == status && NEG == number.status){
		temp = dec(number, *this);
	}
	return temp;
}

const BigInt BigInt::operator-(const long long &number){
	string s = to_string(number);
	BigInt temp(s);
	return *this - temp;
}

const BigInt BigInt::operator+(const BigInt &number){
	BigInt temp("0");
	size_t n = number.get_size();
	if (status == POS && number.get_status() == POS){
		temp = inc(*this, number);// the bug is here
	}
	else{
		if (status == POS && number.get_status() == NEG){
			temp = dec(*this , number);
		}
		else if (status == NEG && number.get_status() == POS)
		{
			temp = dec(number, *this);
		}
		else if (NEG == status && NEG == number.status)
		{
			temp = *this + number;
			temp.status = NEG;
		}
	}
	return temp;
}

const BigInt BigInt::operator+(const long long &number){
	string s = to_string(number);
	BigInt temp(s);
	temp = temp + *this;
	return temp;
}

BigInt& BigInt::operator+=(const BigInt &number){
	*this = *this + number;
	return *this;
}

BigInt& BigInt::operator+=(const long long &number){
	*this = *this + number;
	return *this;
}

BigInt& BigInt::operator-=(const BigInt &number){
	*this = *this - number;
	return *this;
}

BigInt& BigInt::operator-=(const long long &number){
	*this = *this - number;
	return *this;
}

const BigInt BigInt::operator*(const BigInt &number) const{
	BigInt temp("0");
	BigInt res("0");
	int n1 = get_size();
	int n2 = number.get_size();
	long long hold = 0;
	int i = 0;
	for (int j = 0; j < n2; ++j){
		res.clear();
		hold = 0;
		i = 0;
		for (; i < n1; ++i){
			res.num[i + j] = ((num[i] * number.num[j]) + hold) % 10;
			hold = ((num[i] * number.num[j]) + hold) / 10;
		}

		while (hold > 0){
			res.num[i + j ] = hold % 10;
			++i;
			hold = hold / 10;
		}
		temp += res;
	}
	if (temp == 0)
		temp.status = POS;
	else
		temp.status = sign((status + number.status) % 2);
	return temp;
}

const BigInt BigInt::operator*(const long long &number) const{
	string s = to_string(number);
	BigInt temp(s);
	return *this * temp;
}

const BigInt BigInt::operator/(const BigInt &number){
	BigInt temp("0");
	BigInt a(*this);
	a.status = POS;
	BigInt b(number);
	b.status = POS;
	if (static_cast<BigInt>(0) == b)
		throw invalid_argument("divide by zero");

	if (*this == number)
		temp = 1;
	else if (*this < number)
		temp = 0;
	else if (number == 1)
		temp = *this;
	else if (number == 2)
		temp = div2(*this);
	else
	{
		tens();
		BigInt st(2);
		BigInt en(div2(*this));
		while (st <= en){
			BigInt md(div2(st + en));
			if (md * number == *this){
				temp = md;
				break;
			}
			else if (md * number < *this){
				temp = md;
				st = md + 1;
			}
			else{
				en = md - 1;
			}

		}
	}
	if (temp == 0)
		temp.status = POS;
	else
		temp.status = sign((status + number.status) % 2);
	return temp;
}

const BigInt BigInt::operator/(const long long &number){
	string s = to_string(number);
	BigInt temp(s);
	return *this / temp;
}

const BigInt BigInt::operator%(const BigInt &number){
	BigInt a(*this);
	a.status = POS;
	BigInt b(number);
	b.status = POS;
	while (a >= b){
		a -= b;
	}
	return a;
}

const BigInt BigInt::operator%(const long long &number){
	string s = to_string(number);
	BigInt temp(s);
	return *this % temp;
}

BigInt& BigInt::operator*=(const BigInt &number){
	*this = *this * number;
	return *this;
}

BigInt& BigInt::operator*=(const long long &number){
	*this = *this * number;
	return *this;
}

BigInt& BigInt::operator/=(const BigInt &number){
	*this = *this / number;
	return *this;
}

BigInt& BigInt::operator/=(const long long &number){
	*this = *this / number;
	return *this;
}

BigInt& BigInt::operator%=(const BigInt &number){
	*this = *this % number;
	return *this;
}

BigInt& BigInt::operator%=(const long long &number){
	*this = *this % number;
	return *this;
}

BigInt& BigInt::operator++(){
	*this = *this + 1;
	return *this;
}

BigInt& BigInt::operator--(){
	*this = *this - 1;
	return *this;
}

const array<int, BigInt::MAX>& BigInt::get_num() const{
	return num;
}

const BigInt BigInt::inc(const BigInt &a, const BigInt &b){
	BigInt temp("0");
	int hold = 0;
	int n1 = b.get_size();
	int n2 = a.get_size();
	int i;
	for (i = 0; i < n1 || hold != 0; ++i){
		int sum = num[i] + (b.num[i] == -1 ? 0 : b.num[i]);
		temp.num[i] = (sum + hold) % 10;
		hold = ((sum + hold)/ 10);
	}
	for (; i < n2; ++i){
		temp.num[i] = a.num[i];
	}
	temp.status = POS;
	return temp;
}

const BigInt BigInt::dec(const BigInt &num1, const BigInt &num2){
	BigInt temp("0");
	BigInt a(num1);
	a.status = POS;
	BigInt b(num2);
	b.status = POS;
	if (a >= b){
		int n = a.get_size();
		int hold = 0;
		int i = 0;
		for (; i < n; ++i){
			temp.num[i] = (((a.num[i] + hold) - b.num[i]) + 10) % 10;
			if ((a.num[i] + hold) - b.num[i] < 0)
				hold = -1;
			else
				hold = 0;
		}
		temp.status = POS;
	}
	else {

		int n = b.num.size();
		int hold = 0;
		for (int i = 0; i < n; ++i){
			temp.num[i] = (((b.num[i] + hold) - a.num[i]) + 10) % 10;
			if ((b.num[i] + hold)- a.num[i] < 0)
				hold = -1;
			else
				hold = 0;
		}
		temp.status = NEG;
	}
	return temp;
}

const size_t BigInt::get_size() const{
	size_t sz = safe;
	for (int i = safe; i >= 0 && num[i] == 0; --i){
		--sz;
	}
	if (-1 == sz)
		++sz;
	return sz + 1;
}

BigInt::sign BigInt::get_status() const{
	return status;
}

ostream& operator<<(ostream &output, const BigInt &number){

	int n = number.get_size();
	if (number == 0){
		output << 0;
	}
	else
	{
        if(number.status == 1)
            output << '-';
		for (int i = n - 1; i >= 0; --i){
			output << number.num[i];
		}
	}
	return output;
}

istream& operator>>(istream &input, BigInt &number){
	string s;
	input >> s;
	number.set_num(s);
	return input;
}

void BigInt::clear(){
	num.fill(0);
	status = POS;
}

const BigInt BigInt::power(const long long &a, const long long &b){
	if (b == 0)
		return 1;
	BigInt res = power(a, b / 2);
	res *= res;
	if (b % 2)
		res *= a;
	return res;
}


const BigInt BigInt::div2(const BigInt &number){
	BigInt temp(number.num[0] / 2);
	int n = number.get_size();
	for (int i = 1; i < n; ++i){
		temp += (BigInt(ten[i-1]) * number.num[i] * 5);
	}

	temp.status = POS;
	return temp;
}

void BigInt::tens(){
	ten[0] = "1";
	for (int i = 1; i <= 44; ++i){
		ten[i] = ten[i - 1] + "0";
	}
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    while(1){
        string s1;
        string s2;
        s1.clear();
        s2.clear();
        getline(cin , s1);
        if(s1.size() < 1)
            break;
        getline(cin , s2);
        BigInt a(s1);
        BigInt b(s2);
        cout<<a * b;
        blank;
    }



return 0;
}
