import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from tmdbv3api import TMDb, Movie
import requests
from io import BytesIO

# Initialiser l'API TMDb
tmdb = TMDb()
tmdb.api_key = ''  # Remplacez par votre clé API TMDB
tmdb.language = 'fr-FR'

# Initialiser l'objet Movie
movie = Movie()

# Fonction pour rechercher et afficher le film
def search_movie():
    # Effacer l'image précédente, si elle existe
    for widget in frame_image.winfo_children():
        widget.destroy()

    # Obtenir le titre recherché
    movie_title = entry.get()

    # Rechercher le film
    results = movie.search(movie_title)
    
    if results:
        # Obtenir le premier résultat
        movie_data = results[0]
        
        # Afficher le titre du film
        label_title.config(text=movie_data.title)

        # Charger l'affiche du film
        poster_path = movie_data.poster_path
        if poster_path:
            poster_url = f"https://image.tmdb.org/t/p/w500{poster_path}"
            response = requests.get(poster_url)
            img_data = Image.open(BytesIO(response.content))

            # Redimensionner et afficher l'image
            img_data = img_data.resize((300, 450), Image.LANCZOS)
            img = ImageTk.PhotoImage(img_data)
            label_image = tk.Label(frame_image, image=img)
            label_image.image = img  # Conserver une référence à l'image
            label_image.pack()
        else:
            label_title.config(text="Pas d'affiche disponible pour ce film.")
    else:
        label_title.config(text="Aucun film trouvé avec ce titre.")

# Créer la fenêtre principale
root = tk.Tk()
root.title("Affiche du Film")
root.geometry("400x600")

# Zone de recherche
frame_search = ttk.Frame(root)
frame_search.pack(pady=10)

label_entry = ttk.Label(frame_search, text="Entrez le titre du film :")
label_entry.pack(side=tk.LEFT)

entry = ttk.Entry(frame_search, width=30)
entry.pack(side=tk.LEFT, padx=5)

btn_search = ttk.Button(frame_search, text="Rechercher", command=search_movie)
btn_search.pack(side=tk.LEFT)

# Zone pour afficher le titre et l'affiche
label_title = ttk.Label(root, text="", font=("Arial", 16))
label_title.pack(pady=10)

frame_image = ttk.Frame(root)
frame_image.pack()

# Lancer l'interface
root.mainloop()
