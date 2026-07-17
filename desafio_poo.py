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

# 2. La Clase Hija con Herencia
class SuscripcionPremium(Suscripcion):
    def __init__(self, usuario, precio_base, codigo_tarjeta, calidad_video):
        # Usamos super() en la primera línea para heredar del padre
        super().__init__(usuario, precio_base, codigo_tarjeta)
        self.calidad_video = calidad_video

    # 3. Aplicar Polimorfismo (Reescribir el método)
    def reproducir_contenido(self):
        print(f"El usuario {self.usuario} está viendo contenido en máxima definición {self.calidad_video}.")


# --- Bloque de Pruebas en consola ---
if __name__ == "__main__":
    print("--- Probando Suscripción Estándar ---")
    sub_estandar = Suscripcion("Jordy", 7.99, "1234567890123456")
    sub_estandar.reproducir_contenido()
    print(f"Tarjeta: {sub_estandar.obtener_tarjeta_segura()}")

    print("\n--- Probando Suscripción Premium ---")
    sub_premium = SuscripcionPremium("Jihyo", 15.99, "9876543210987654", "4K")
    sub_premium.reproducir_contenido()
    print(f"Tarjeta: {sub_premium.obtener_tarjeta_segura()}")