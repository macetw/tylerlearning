def sample_method(simple_param, list_param, dict_param):
	print("Printing simple parameter")
	print(simple_param)
	print()
	print("Printing a list")
	for item in list_param:
		print(item)
	print()
	print("Printing a dictionary")
	for key, value in dict_param.items():
		print(f"{key} = {value}")
	print()

if __name__ == '__main__':
	# Method invocation using named parameters
	# Order of parameters doesn't matter.
	sample_method(list_param = [1, 2, 3, 4, 5],
                simple_param = "I'm a simple param",
		dict_param = { "key 1": "value 1",
                    "key 2": "value2" })


