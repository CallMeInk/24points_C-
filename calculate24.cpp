#include<iostream>
using namespace std;

double arr[4];
double record[3][3];
int oprecord[3];
double goalNum = 24;
bool done = false;
//abc change

double calculate(double op1,double op2,int op3){
	if (op3 == 0) return op1 + op2;
	else if (op3 == 1) return op1 - op2;
	else if (op3 == 2) return op1 * op2;
	else return op1 / op2;
}

double abs(double x){
	return (x>0)?x:-x;
}

int judge(double a,double b){
	if (abs(a + b -goalNum) < 0.000001) return 1;
	else if (abs(a - b -goalNum) < 0.000001) return 2;
	else if (abs(b - a -goalNum) < 0.000001) return 3;
	else if (abs(a * b -goalNum) < 0.000001) return 4;
	else if ((b != 0) && (abs(a / b -goalNum) < 0.000001))return 5;
	else if ((a != 0) && (abs(b / a -goalNum) < 0.000001))return 6;
	else return 0;
}

void printResult(){
	char op[4];
	op[0] = '+';
	op[1] = '-';
	op[2] = '*';
	op[3] = '/';
	cout << record[0][0] << ' ' << op[oprecord[0]] << ' ' << record[0][1] << " = " << calculate(record[0][0],record[0][1],oprecord[0]) << endl;
	cout << record[1][0] << ' ' << op[oprecord[1]] << ' ' << record[1][1] << " = " << calculate(record[1][0],record[1][1],oprecord[1]) <<endl;
	cout << record[2][0] << ' ' << op[oprecord[2]] << ' ' << record[2][1] << " = 24" << endl;
}

void cal(int num, double work[4]){
	double tmp[4];
	
	if (!done && num == 2){
		int result = judge(work[0],work[1]);
		if (result == 0) return;
		if (result == 1){
			record[2][0] = work[0];
			record[2][1] = work[1];
			oprecord[2] = 0;
		}else if (result == 2){
			record[2][0] = work[0];
			record[2][1] = work[1];
			oprecord[2] = 1;
		}else if (result == 3){
			record[2][0] = work[1];
			record[2][1] = work[0];
			oprecord[2] = 1;
		}else if (result == 4){
			record[2][0] = work[0];
			record[2][1] = work[1];
			oprecord[2] = 2;
		}else if (result == 5){
			record[2][0] = work[0];
			record[2][1] = work[1];
			oprecord[2] = 3;
		}else if (result == 6){
			record[2][0] = work[1];
			record[2][1] = work[0];
			oprecord[2] = 3;
		}
		done = true;
		printResult();
	}else if (!done && num == 3){
		//a[0] a[1]
		if (done) return;
		record[1][0] = work[0];
		record[1][1] = work[1];
		oprecord[1] = 0;
		tmp[0] = work[2];
		tmp[1] = work[0] + work[1];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[0];
		record[1][1] = work[1];
		oprecord[1] = 1;
		tmp[0] = work[2];
		tmp[1] = work[0] - work[1];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[1];
		record[1][1] = work[0];
		oprecord[1] = 1;
		tmp[0] = work[2];
		tmp[1] = work[1] - work[0];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[0];
		record[1][1] = work[1];
		oprecord[1] = 2;
		tmp[0] = work[2];
		tmp[1] = work[0] * work[1];
		cal(2,tmp);
		
		if (done) return;
		if (work[1] != 0){
			record[1][0] = work[0];
			record[1][1] = work[1];
			oprecord[1] = 3;
			tmp[0] = work[2];
			tmp[1] = work[0] / work[1];
			cal(2,tmp);
		}
		
		if (done) return;
		if (work[0] != 0){
			record[1][0] = work[1];
			record[1][1] = work[0];
			oprecord[1] = 3;
			tmp[0] = work[2];
			tmp[1] = work[1] / work[0];
			cal(2,tmp);
		}
		
		
		//a[0] a[2]
		if (done) return;
		record[1][0] = work[0];
		record[1][1] = work[2];
		oprecord[1] = 0;
		tmp[0] = work[1];
		tmp[1] = work[0] + work[2];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[0];
		record[1][1] = work[2];
		oprecord[1] = 1;
		tmp[0] = work[1];
		tmp[1] = work[0] - work[2];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[2];
		record[1][1] = work[0];
		oprecord[1] = 1;
		tmp[0] = work[1];
		tmp[1] = work[2] - work[0];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[0];
		record[1][1] = work[2];
		oprecord[1] = 2;
		tmp[0] = work[1];
		tmp[1] = work[0] * work[2];
		cal(2,tmp);
		
		if (done) return;
		if (work[1] != 0){
			record[1][0] = work[0];
			record[1][1] = work[2];
			oprecord[1] = 3;
			tmp[0] = work[1];
			tmp[1] = work[0] / work[2];
			cal(2,tmp);
		}

		if (done) return;
		if (work[0] != 0){
			record[1][0] = work[2];
			record[1][1] = work[0];
			oprecord[1] = 3;
			tmp[0] = work[1];
			tmp[1] = work[2] / work[0];
			cal(2,tmp);
		}
		
		//a[1] a[2]
		if (done) return;
		record[1][0] = work[1];
		record[1][1] = work[2];
		oprecord[1] = 0;
		tmp[0] = work[0];
		tmp[1] = work[1] + work[2];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[1];
		record[1][1] = work[2];
		oprecord[1] = 1;
		tmp[0] = work[0];
		tmp[1] = work[1] - work[2];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[2];
		record[1][1] = work[1];
		oprecord[1] = 1;
		tmp[0] = work[0];
		tmp[1] = work[2] - work[1];
		cal(2,tmp);
		
		if (done) return;
		record[1][0] = work[1];
		record[1][1] = work[2];
		oprecord[1] = 2;
		tmp[0] = work[0];
		tmp[1] = work[1] * work[2];
		cal(2,tmp);
		
		if (done) return;
		if (work[1] != 0){
			record[1][0] = work[1];
			record[1][1] = work[2];
			oprecord[1] = 3;
			tmp[0] = work[0];
			tmp[1] = work[1] / work[2];
			cal(2,tmp);
		}

		if (done) return;
		if (work[0] != 0){
			record[1][0] = work[2];
			record[1][1] = work[1];
			oprecord[1] = 3;
			tmp[0] = work[0];
			tmp[1] = work[2] / work[1];
			cal(2,tmp);
		}
	}else if (!done){
		
		//a[0] a[1]
		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[1];
		oprecord[0] = 0;
		tmp[0] = work[2];
		tmp[1] = work[3];
		tmp[2] = work[0] + work[1];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[1];
		oprecord[0] = 1;
		tmp[0] = work[2];
		tmp[1] = work[3];
		tmp[2] = work[0] - work[1];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[1];
		record[0][1] = work[0];
		oprecord[0] = 1;
		tmp[0] = work[2];
		tmp[1] = work[3];
		tmp[2] = work[1] - work[0];
		cal(3,tmp);

		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[1];
		oprecord[0] = 2;
		tmp[0] = work[2];
		tmp[1] = work[3];
		tmp[2] = work[0] * work[1];
		cal(3,tmp);
		
		if (done) return;
		if (work[1] != 0){
			record[0][0] = work[0];
			record[0][1] = work[1];
			oprecord[0] = 3;
			tmp[0] = work[2];
			tmp[1] = work[3];
			tmp[2] = work[0] / work[1];
		    cal(3,tmp);
		}
		if (done) return;
		if (work[0] != 0){
			record[0][0] = work[1];
			record[0][1] = work[0];
			oprecord[0] = 3;
			tmp[0] = work[2];
			tmp[1] = work[3];
			tmp[2] = work[1] / work[0];
		    cal(3,tmp);
		}
		
		//a[0] a[2]
		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[2];
		oprecord[0] = 0;
		tmp[0] = work[1];
		tmp[1] = work[3];
		tmp[2] = work[0] + work[2];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[2];
		oprecord[0] = 1;
		tmp[0] = work[1];
		tmp[1] = work[3];
		tmp[2] = work[0] - work[2];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[2];
		record[0][1] = work[0];
		oprecord[0] = 1;
		tmp[0] = work[1];
		tmp[1] = work[3];
		tmp[2] = work[2] - work[0];
		cal(3,tmp);

		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[2];
		oprecord[0] = 2;
		tmp[0] = work[1];
		tmp[1] = work[3];
		tmp[2] = work[0] * work[2];
		cal(3,tmp);
		
		if (done) return;
		if (work[2] != 0){
			record[0][0] = work[0];
			record[0][1] = work[2];
			oprecord[0] = 3;
			tmp[0] = work[1];
			tmp[1] = work[3];
			tmp[2] = work[0] / work[2];
		    cal(3,tmp);
		}
		if (done) return;
		if (work[0] != 0){
			record[0][0] = work[2];
			record[0][1] = work[0];
			oprecord[0] = 3;
			tmp[0] = work[1];
			tmp[1] = work[3];
			tmp[2] = work[2] / work[0];
		    cal(3,tmp);
		}
		
		//a[0] a[3]
		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[3];
		oprecord[0] = 0;
		tmp[0] = work[1];
		tmp[1] = work[2];
		tmp[2] = work[0] + work[3];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[3];
		oprecord[0] = 1;
		tmp[0] = work[1];
		tmp[1] = work[2];
		tmp[2] = work[0] - work[3];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[3];
		record[0][1] = work[0];
		oprecord[0] = 1;
		tmp[0] = work[1];
		tmp[1] = work[2];
		tmp[2] = work[3] - work[0];
		cal(3,tmp);

		if (done) return;
		record[0][0] = work[0];
		record[0][1] = work[3];
		oprecord[0] = 2;
		tmp[0] = work[1];
		tmp[1] = work[2];
		tmp[2] = work[0] * work[3];
		cal(3,tmp);
		
		if (done) return;
		if (work[3] != 0){
			record[0][0] = work[0];
			record[0][1] = work[3];
			oprecord[0] = 3;
			tmp[0] = work[1];
			tmp[1] = work[2];
			tmp[2] = work[0] / work[3];
		    cal(3,tmp);
		}
		if (done) return;
		if (work[0] != 0){
			record[0][0] = work[3];
			record[0][1] = work[0];
			oprecord[0] = 3;
			tmp[0] = work[1];
			tmp[1] = work[2];
			tmp[2] = work[3] / work[0];
		    cal(3,tmp);
		}
		
		
		//a[1] a[2]
		if (done) return;
		record[0][0] = work[1];
		record[0][1] = work[2];
		oprecord[0] = 0;
		tmp[0] = work[0];
		tmp[1] = work[3];
		tmp[2] = work[1] + work[2];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[1];
		record[0][1] = work[2];
		oprecord[0] = 1;
		tmp[0] = work[0];
		tmp[1] = work[3];
		tmp[2] = work[1] - work[2];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[2];
		record[0][1] = work[1];
		oprecord[0] = 1;
		tmp[0] = work[0];
		tmp[1] = work[3];
		tmp[2] = work[2] - work[1];
		cal(3,tmp);

		if (done) return;
		record[0][0] = work[1];
		record[0][1] = work[2];
		oprecord[0] = 2;
		tmp[0] = work[0];
		tmp[1] = work[3];
		tmp[2] = work[1] * work[2];
		cal(3,tmp);
		
		if (done) return;
		if (work[3] != 0){
			record[0][0] = work[1];
			record[0][1] = work[2];
			oprecord[0] = 3;
			tmp[0] = work[0];
			tmp[1] = work[3];
			tmp[2] = work[1] / work[2];
		    cal(3,tmp);
		}
		if (done) return;
		if (work[0] != 0){
			record[0][0] = work[2];
			record[0][1] = work[1];
			oprecord[0] = 3;
			tmp[0] = work[0];
			tmp[1] = work[3];
			tmp[2] = work[2] / work[1];
		    cal(3,tmp);
		}
		
		
		//a[1] a[3]
		if (done) return;
		record[0][0] = work[1];
		record[0][1] = work[3];
		oprecord[0] = 0;
		tmp[0] = work[0];
		tmp[1] = work[2];
		tmp[2] = work[1] + work[3];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[1];
		record[0][1] = work[3];
		oprecord[0] = 1;
		tmp[0] = work[0];
		tmp[1] = work[2];
		tmp[2] = work[1] - work[3];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[3];
		record[0][1] = work[1];
		oprecord[0] = 1;
		tmp[0] = work[0];
		tmp[1] = work[2];
		tmp[2] = work[3] - work[1];
		cal(3,tmp);

		if (done) return;
		record[0][0] = work[1];
		record[0][1] = work[3];
		oprecord[0] = 2;
		tmp[0] = work[0];
		tmp[1] = work[2];
		tmp[2] = work[1] * work[3];
		cal(3,tmp);
		
		if (done) return;
		if (work[3] != 0){
			record[0][0] = work[1];
			record[0][1] = work[3];
			oprecord[0] = 3;
			tmp[0] = work[0];
			tmp[1] = work[2];
			tmp[2] = work[1] / work[3];
		    cal(3,tmp);
		}
		
		if (done) return;
		if (work[0] != 0){
			record[0][0] = work[3];
			record[0][1] = work[1];
			oprecord[0] = 3;
			tmp[0] = work[0];
			tmp[1] = work[2];
			tmp[2] = work[3] / work[1];
		    cal(3,tmp);
		}
		
		//a[2] a[3]
		if (done) return;
		record[0][0] = work[2];
		record[0][1] = work[3];
		oprecord[0] = 0;
		tmp[0] = work[0];
		tmp[1] = work[1];
		tmp[2] = work[2] + work[3];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[2];
		record[0][1] = work[3];
		oprecord[0] = 1;
		tmp[0] = work[0];
		tmp[1] = work[1];
		tmp[2] = work[2] - work[3];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[3];
		record[0][1] = work[2];
		oprecord[0] = 1;
		tmp[0] = work[0];
		tmp[1] = work[1];
		tmp[2] = work[3] - work[2];
		cal(3,tmp);
		
		if (done) return;
		record[0][0] = work[2];
		record[0][1] = work[3];
		oprecord[0] = 2;
		tmp[0] = work[0];
		tmp[1] = work[1];
		tmp[2] = work[2] * work[3];
		cal(3,tmp);
		
		if (done) return;
		if (work[3] != 0){
			record[0][0] = work[2];
			record[0][1] = work[3];
			oprecord[0] = 3;
			tmp[0] = work[0];
			tmp[1] = work[1];
			tmp[2] = work[2] / work[3];
		    cal(3,tmp);
		}
		if (done) return;
		if (work[0] != 0){
			record[0][0] = work[3];
			record[0][1] = work[2];
			oprecord[0] = 3;
			tmp[0] = work[0];
			tmp[1] = work[1];
			tmp[2] = work[3] / work[2];
		    cal(3,tmp);
		}
	}
}

int main(){
	while(arr[0] != 3333){
		cout << "请输入四个数，以空格分隔：";
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		done = false;
		cal(4,arr);
	}
	
	return 0;
}
