def log(message, level="INFO"):
    """带颜色的日志输出"""
    from datetime import datetime

    COLORS = {
        "DEBUG": "\033[94m",  # 蓝色
        "INFO": "\033[92m",  # 绿色
        "WARNING": "\033[93m",  # 黄色
        "ERROR": "\033[91m",  # 红色
        "CRITICAL": "\033[1;91m"  # 加粗红色
    }
    RESET = "\033[0m"

    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    colored_level = f"{COLORS.get(level, '')}{level}{RESET}"
    print(f"[{timestamp}] [{colored_level}] {message}")

def is_roman_num_str(num_str:str) -> bool:
    """
    判断是否为有效罗马数字

    参数:
    num_str (str): 全小写或者全大写字符串

    返回:
    bool: 如果是有效罗马数字返回True, 否则返回False.
    """
    valid_lower_chars = {'i', 'v', 'x', 'l', 'c', 'd', 'm'}
    valid_upper_chars = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}
    if not all(c in valid_lower_chars for c in num_str) and not all(c in valid_upper_chars for c in num_str):
        return False

    upper_num_str = num_str.upper()

    # 检查是否存在非法的连续重复
    if 'IIII' in upper_num_str or 'XXXX' in upper_num_str or 'CCCC' in upper_num_str:
        return False

    if 'VV' in upper_num_str or 'LL' in upper_num_str or 'DD' in upper_num_str:
        return False
    
    # 检查是否存在非法的前缀组合
    invalid_prefix = {'IL', 'IC', 'ID', 'IM', 
                      'XD', 'XM', 'VX', 'VL', 'VC', 'VD', 'VM'}
    for pair in invalid_prefix:
        if pair in upper_num_str:
            return False
    
    # 验证减法规则（只能出现一次小数字在大数字左边）
    subtractive_pairs = {'IV', 'IX', 'XL', 'XC', 'CD', 'CM'}
    for pair in subtractive_pairs:
        if upper_num_str.count(pair) > 1:
            return False

    # 定义罗马数字到整数的映射
    roman_values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 
                    'C': 100, 'D': 500, 'M': 1000}

    # 检查减法后的字符是否有效
    for i in range(len(upper_num_str) - 1):
        current = upper_num_str[i]
        next_char = upper_num_str[i + 1]
        if roman_values[current] < roman_values[next_char]:
            # 小数字在大数字左边，检查是否为合法的减法组合
            valid_subtract = any(pair == current + next_char for pair in subtractive_pairs)
            if not valid_subtract:
                return False
    
    # 所有检查都通过，认为是有效罗马数字
    return True

