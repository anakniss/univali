def add_number_to_list(numbers_list, number):
    numbers_list.append(number)

def get_first_element(numbers_list):
    if len(numbers_list) > 0:
        return numbers_list[0]
    else:
        return None

def get_last_element(numbers_list):
    if len(numbers_list) > 0:
        return numbers_list[-1]
    else:
        return None

def get_elements_between_first_and_last(numbers_list):
    if len(numbers_list) < 2:
        return None
    else:
        return len(numbers_list) - 2