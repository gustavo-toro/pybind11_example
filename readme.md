Para compilar
```
c++ -O3 -Wall -shared -std=c++17 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)
```

Debería haberse creado un archivo .so que es la librería. Para probar si funciona, puedes ejecutar el example.py
```
python3 example.py
```
