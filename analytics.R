# EduLogic Analytics - Simulación de Impacto
if(!require(ggplot2)) install.packages("ggplot2")
library(ggplot2)

# Crear datos simulados
datos <- data.frame(
  Grupo = c(rep("Sin EduLogic", 50), rep("Con EduLogic", 50)),
  Calificacion = c(rnorm(50, mean=6.5, sd=1), rnorm(50, mean=8.5, sd=0.8))
)

# Generar la gráfica de impacto
grafica <- ggplot(datos, aes(x=Grupo, y=Calificacion, fill=Grupo)) +
  geom_boxplot() +
  labs(title="Impacto de EduLogic en el Rendimiento Académico",
       subtitle="Comparativa de calificaciones en Ingeniería",
       x="Metodología", y="Calificación Final") +
  theme_minimal() +
  scale_fill_manual(values=c("#3498db", "#2ecc71"))

# Mostrar gráfica
print(grafica)

# Guardar para el PDF
# ggsave("impacto_edulogic.png", plot=grafica, width=6, height=4)
