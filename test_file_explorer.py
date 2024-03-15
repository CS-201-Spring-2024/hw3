import pytest
files =['output_avl_find_by_date_large.txt', 'output_avl_find_by_date_medium.txt', 'output_avl_find_by_date_small.txt', 'output_avl_find_by_name_and_date_large.txt', 'output_avl_find_by_name_and_date_medium.txt', 'output_avl_find_by_name_and_date_small.txt', 'output_avl_find_by_name_and_size_large.txt', 'output_avl_find_by_name_and_size_medium.txt', 'output_avl_find_by_name_and_size_small.txt', 'output_avl_find_by_name_large.txt', 'output_avl_find_by_name_medium.txt', 'output_avl_find_by_name_small.txt', 'output_avl_find_files_created_during_large.txt', 'output_avl_find_files_created_during_medium.txt', 'output_avl_find_files_created_during_small.txt', 'output_bst_find_by_date_large.txt', 'output_bst_find_by_date_medium.txt', 'output_bst_find_by_date_small.txt', 'output_bst_find_by_name_and_date_large.txt', 'output_bst_find_by_name_and_date_medium.txt', 'output_bst_find_by_name_and_date_small.txt', 'output_bst_find_by_name_and_size_large.txt', 'output_bst_find_by_name_and_size_medium.txt', 'output_bst_find_by_name_and_size_small.txt', 'output_bst_find_by_name_large.txt', 'output_bst_find_by_name_medium.txt', 'output_bst_find_by_name_small.txt', 'output_bst_find_files_created_during_large.txt', 'output_bst_find_files_created_during_medium.txt', 'output_bst_find_files_created_during_small.txt']

@pytest.mark.parametrize("i", range(0, len(files)))
def test_file_explorer(i):
    

    with open("./test-output/"+files[i], 'r') as f:
        if "find_files_created_during" not in files[i]:
            print(files[i],)
            assert f.read() == open("./output/"+files[i], 'r').read()
        else:
            # ignore the first line of the output file
            assert f.readlines()[1:] == open("./output/"+files[i], 'r').readlines()[1:]

