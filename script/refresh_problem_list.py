import os
from pathlib import Path

__CURRENT_FILE_PATH = Path(__file__).resolve()
__SCRIPT_DIR = os.path.dirname(__CURRENT_FILE_PATH)
__ROOT_DIR = os.path.dirname(__SCRIPT_DIR)
_CODE_DIR = __ROOT_DIR + "/code"
_LEETCODE_SRC_DIR = _CODE_DIR + "/leetcode/src/"
_PROBLEM_LIST_FILE = __ROOT_DIR + "/problem_list.md"


def refresh_problem_list() -> None:
    file_name_list: list = []
    with os.scandir(_LEETCODE_SRC_DIR) as entries:
        for entry in entries:
            if entry.is_file():
                file_name_list.append(os.path.basename(entry.path).rsplit(".", 1)[0])
    file_name_list.sort()
    with open(_PROBLEM_LIST_FILE, "w", encoding="utf-8") as file:
        for file_name in file_name_list:
            file.write(f"{file_name}\n")
    return None


if __name__ == "__main__":
    refresh_problem_list()
