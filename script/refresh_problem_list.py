import os
from pathlib import Path

__CURRENT_FILE_PATH = Path(__file__).resolve()
__SCRIPT_DIR = os.path.dirname(__CURRENT_FILE_PATH)
__ROOT_DIR = os.path.dirname(__SCRIPT_DIR)
_CODE_DIR = __ROOT_DIR + "/code"
_LEETCODE_SRC_DIR = _CODE_DIR + "/leetcode/src/"
_PROBLEM_LIST_FILE = _CODE_DIR + "/problem_list.md"


def get_all_file_name(src_dir: Path, file_name_list: list) -> None:
    with os.scandir(src_dir) as entries:
        for entry in entries:
            if entry.is_file():
                file_name_list.append(os.path.basename(entry.path).rsplit(".", 1)[0])
            elif entry.is_dir():
                get_all_file_name(entry, file_name_list)


def refresh_problem_list() -> None:
    file_name_list: list = []
    get_all_file_name(_LEETCODE_SRC_DIR, file_name_list)
    file_name_list.sort()
    with open(_PROBLEM_LIST_FILE, "w", encoding="utf-8") as file:
        file.write("# Problem List\n\n")
        for file_name in file_name_list:
            file.write(f"{file_name}\n")
    return None


if __name__ == "__main__":
    refresh_problem_list()
