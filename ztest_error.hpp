
#pragma once
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//ZTestFailureException �����Զ���Ĳ���ʧ���쳣��
class ZTestFailureException : public std::exception {
private:
  string _msg;

public:
    /**
 * @description: ���캯������ʼ������ʧ���쳣��Ϣ
 * @param test_name ʧ�ܵĲ�����������
 * @param expected �����Ĳ��Խ��
 * @param actual ʵ�ʵĲ��Խ��
 */
  ZTestFailureException(const string &test_name, const string &expected,
                        const string &actual) {
    ostringstream oss;
    oss << "Test Failure in " << test_name << ":\n"
        << "  Expected: " << expected << "\n"
        << "  Actual  : " << actual;
    _msg = oss.str();
  }
  /**
 * @description: ��ȡ�쳣��Ϣ�ַ���
 * @return �쳣��Ϣ��C����ַ���ָ��
 */
  const char *what() const noexcept override { return _msg.c_str(); }
};
