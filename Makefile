# Nom de l'exécutable
NAME = SFMLDevKit

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -Werror 

# Bibliothèques SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Répertoires
SRC_DIR = src
BUILD_DIR = build

# Fichiers sources
SRC = $(shell find $(SRC_DIR) -name '*.cpp')

# Générer les fichiers objets dans build/
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

# Création de l'exécutable
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(SFML_LIBS)

# Compilation des fichiers sources en fichiers objets dans build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Création du dossier build/ si non existant
$(BUILD_DIR):
	@ mkdir -p $(dir $(OBJ))

# Nettoyage des fichiers objets
clean:
	@ rm -rf $(BUILD_DIR)

# Nettoyage complet
fclean: clean
	@ rm -f $(NAME)

# Recompile tout
re: fclean all
