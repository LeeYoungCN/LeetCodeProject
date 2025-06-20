import argparse
import os
from pathlib import Path
from refresh_problem_list import refresh_problem_list

__CURRENT_FILE_PATH = Path(__file__).resolve()
__SCRIPT_DIR = os.path.dirname(__CURRENT_FILE_PATH)
__ROOT_DIR = os.path.dirname(__SCRIPT_DIR)

TEST_SRC_DIR = __ROOT_DIR + "/test/"
LEETCODE_SRC_DIR = __ROOT_DIR + "/leetcode/src/"
LEETCODE_INC_DIR = __ROOT_DIR + "/leetcode/inc/"
TEMPLATE_DIR = __SCRIPT_DIR + "/template/"

TEMPLATE_HEAD_FILE = TEMPLATE_DIR + "leetcode_head_file.template"
TEMPLATE_SRC_FILE = TEMPLATE_DIR + "leetcode_src_file.template"
TEMPLATE_TEST_FILE = TEMPLATE_DIR + "leetcode_test_file.template"

def log(message, level="INFO"):
    """带颜色的日志输出"""
    from datetime import datetime
    
    COLORS = {
        "DEBUG": "\033[94m",    # 蓝色
        "INFO": "\033[92m",     # 绿色
        "WARNING": "\033[93m",  # 黄色
        "ERROR": "\033[91m",    # 红色
        "CRITICAL": "\033[1;91m"  # 加粗红色
    }
    RESET = "\033[0m"

    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    colored_level = f"{COLORS.get(level, '')}{level}{RESET}"
    print(f"[{timestamp}] [{colored_level}] {message}")

class LeetcodeFile:
    def __init__(self, prefix:str, url:str, function:str, class_name:str = None):
        self.__problem_prefix = prefix
        self.__url = url
        self.__funciton = function
        self.__class_name = class_name
        self.__func_ret_type = None
        self.__func_name = None
        self.__func_params = None
        self.__param_names = None
        self.__leetcode_file_name = None
        self.__leetcode_head_file = None
        self.__leetcode_src_file = None
        self.__test_src_file = None
        self.__leetcode_class_name = None
        self.__test_class_name = None
        self.__def_str = None

        self.__init_func_data()
        self.__init_class_data()
    
    def __init_func_data(self):
        # long long func_name(vector<int>& x, string y)

        """ long long func_name """
        func_name_with_ret = self.__funciton.split('(')[0]
        """ vector<int>& x, string y """
        self.__func_params = self.__funciton.split('(')[1].split(')')[0]
        """ func_name """
        self.__func_name = func_name_with_ret.split(' ')[-1]
        """ long long """
        self.__func_ret_type = func_name_with_ret.rsplit(' ', 1)[0]
        """ x, y """
        param_parts = self.__func_params.split()

        self.__param_names = ""
        for i in range(0, len(param_parts)):
            if i % 2 == 1:
                self.__param_names += param_parts[i]
                if i != len(param_parts) - 1:
                    self.__param_names += " "

    def __init_class_data(self):
        if self.__class_name is None:
            """ https://leetcode.cn/problems/class-name/description -> class-name """
            raw_class_name = self.__url.split('/')[4]
        else:
            raw_class_name = self.__class_name
        """ 前缀全大写: lc1234 -> LC1234"""
        prefix_upper = self.__problem_prefix.upper()
        """ 下划线: class-name -> class_name """
        class_name_snake = raw_class_name.replace("-", "_")
        """ 匈牙利转大驼峰: class_name -> ClassName """
        class_name_pascal = ""
        for name_part in class_name_snake.split('_'):
            class_name_pascal += name_part[0].upper() + name_part[1:]
        """ lc1234_class_name """
        self.__leetcode_file_name = self.__problem_prefix + "_" + class_name_snake
        """ lc1234_class_name.h """
        self.__leetcode_head_file = self.__leetcode_file_name + ".h"
        """ lc1234_class_name.cpp """
        self.__leetcode_src_file = self.__leetcode_file_name + ".cpp"
        """ test_lc1234_class_name.cpp """
        self.__test_src_file = "test_" + self.__leetcode_file_name + ".cpp"
        """ LC1234_ClassName """
        self.__leetcode_class_name = prefix_upper + "_" + class_name_pascal
        """ TEST_LC1234 """
        self.__test_class_name = "TEST_" + prefix_upper
        """ LC1234_CLASS_NAME_H """
        self.__def_str = self.__leetcode_file_name.upper() + "_H"

    def print_data(self):
        log(f"func_name:          {self.__func_name}")
        log(f"func_ret_type:      {self.__func_ret_type}")
        log(f"func_params:        {self.__func_params}")
        log(f"param_names:        {self.__param_names}")
        log(f"src_file_name:      {self.__leetcode_file_name}")
        log(f"class_name:         {self.__leetcode_class_name}")
        log(f"test_class_name:    {self.__test_class_name}")
        log(f"def_str:            {self.__def_str}")

    def __create_file_by_template(self, template_file, new_file):
        if os.path.exists(new_file):
            log(f"{new_file} already exist.", "ERROR")
            return
        
        if not os.path.exists(template_file):
            log(f"{new_file} not exist!", "ERROR")

        from datetime import datetime
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        replace_list = [
            ["URL_STR",         self.__url],
            ["CLASS_NAME",      self.__leetcode_class_name],
            ["DEF_STR",         self.__def_str],
            ["HEAD_FILE_NAME",  self.__leetcode_head_file],
            ["TEST_CLASSNAME",  self.__test_class_name],
            ["FUNC_RET_TYPE",   self.__func_ret_type],
            ["FUNC_PARAM",      self.__func_params],
            ["CLASS_FUNC",      self.__func_name],
            ["TIME_STR",        timestamp],
            ["PARAM_NAMES",     self.__param_names]
        ]    

        with open(template_file, 'r', encoding='utf-8') as infile:
            lines = infile.readlines()
        
        with open(new_file, 'w', encoding='utf-8') as outfile:
            for line in lines:
                for replace_pair in replace_list:
                    line = line.replace(replace_pair[0], replace_pair[1])
                outfile.write(line)
        
        log(f"Create [{new_file}] success.")

    def create_files(self):
        HEAD_FILE_PATH = LEETCODE_INC_DIR + self.__leetcode_head_file
        SRC_FILE_PATH = LEETCODE_SRC_DIR + self.__leetcode_src_file
        TEST_FILE_PATH = TEST_SRC_DIR + self.__test_src_file
        self.__create_file_by_template(TEMPLATE_HEAD_FILE, HEAD_FILE_PATH)
        self.__create_file_by_template(TEMPLATE_SRC_FILE, SRC_FILE_PATH)
        self.__create_file_by_template(TEMPLATE_TEST_FILE, TEST_FILE_PATH)

def is_valid_arg(arg:str) -> bool:
    return not (arg is None or arg == "")

def main():
    parser = argparse.ArgumentParser(description='创建leetcode文件.')
    parser.add_argument('-p', '--prefix', help='Problem prefix.')
    parser.add_argument('-u', '--url', help='Problem URL.')
    parser.add_argument('-f', '--function', help='Problem function.')
    parser.add_argument('-n', '--class_name', help='Class name.')
    args = parser.parse_args()

    if not is_valid_arg(args.prefix):
        log(f"Prefix invalid {args.prefix}.", "ERROR")
        return 1
    
    if not is_valid_arg(args.url) and not is_valid_arg(args.class_name):
        log(f"Url or class_name invalid.", "ERROR")
        return 1
    
    if not is_valid_arg(args.function):
        log(f"function invalid {args.function}.", "ERROR")
        return 1
    
    obj = LeetcodeFile(args.prefix, args.url, args.function, args.class_name)
    obj.print_data()
    obj.create_files()
    refresh_problem_list()
    return None


if __name__ == "__main__":
    main()
