import pymongo
from datetime import datetime
 
# 1. DIRECCIÓN DE CONEXIÓN
# Si MongoDB está en tu propia computadora:
MONGO_URI = "mongodb+srv://idUser:pass001#@cluster0.tjcodey.mongodb.net/?appName=Cluster0"
 
# Si usas MongoDB Atlas (en la nube), tu URI se ve así:
# MONGO_URI = "mongodb+srv://usuario:password@cluster.mongodb.net/"
 
try:
    # 2. CREAR EL CLIENTE (Capa de Transporte/Conexión)
    # Le damos un tiempo de espera breve (5 segundos) por si el servidor no responde
    cliente = pymongo.MongoClient(MONGO_URI, serverSelectionTimeoutMS=5000)
 
    # Probamos si el servidor está vivo
    cliente.admin.command('ping')
    print("¡Conexión exitosa a MongoDB!")
 
    # 3. SELECCIONAR LA BASE DE DATOS Y LA COLECCIÓN
    db = cliente["iot_database"]            # Si no existe, MongoDB la crea sola
    coleccion = db["lecturas_sensores"]     # Equivalente a la "tabla"
 
    # 4. INSERTAR UN DOCUMENTO (Escribir datos)
    # Los datos se mandan como un Diccionario de Python (Formato JSON)
    nuevo_dato = {
        "dispositivo_id": "ESP8266_Sensor_1",
        "temperatura": 24.5,
        "humedad": 60,
        "fecha": datetime.now()
    }
 
    resultado = coleccion.insert_one(nuevo_dato)
    print(f"Documento insertado con el ID: {resultado.inserted_id}")
 
    # 5. CONSULTAR DATOS (Leer la base de datos)
    print("\n--- ÚLTIMAS LECTURAS REGISTRADAS ---")
    # Buscamos las lecturas del ESP8266_Sensor_1
    cursor = coleccion.find({"dispositivo_id": "ESP8266_Sensor_1"})
 
    for documento in cursor:
        print(documento)
 
except pymongo.errors.ServerSelectionTimeoutError:
    print("Error: No se pudo conectar al servidor de MongoDB. ¿Está encendido?")
except Exception as e:
    print(f"Ocurrió un error inesperado: {e}")
finally:
    # Cerramos la conexión al terminar
    cliente.close()
 