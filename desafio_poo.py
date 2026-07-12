class Suscripcion:
    def __init__(self, usuario, precio_base, codigo_tarjeta):
        self.usuario = usuario
        self.precio_base = precio_base
        # Atributo privado
        self.__codigo_tarjeta = str(codigo_tarjeta)

    # Método seguro (Getter) para mostrar solo los últimos 4 dígitos
    def obtener_tarjeta_segura(self):
        if len(self.__codigo_tarjeta) >= 4:
            ultimos_digitos = self.__codigo_tarjeta[-4:]
            return f"XXXX-{ultimos_digitos}"
        return "Tarjeta inválida"

    def reproducir_contenido(self):
        print(f"El usuario {self.usuario} está viendo contenido estándar.")