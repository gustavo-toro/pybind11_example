import example

document = "aaaa"

print("[python] address:  ", hex(id(document)))

iterator = example.finditer(document)
print("the document is", iterator.get_document())

print(document)
