import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from tmdbv3api import TMDb, Movie
import requests
from io import BytesIO
import random

# Api init
tmdb = TMDb()
tmdb.api_key = 'API_KEY'
tmdb.language = 'fr-FR'

movie = Movie()

def display_film(title, x):
    y_pos = 250
    results = movie.search(title)

    if results:
        movie_data = results[0]

        label_title = tk.Label(root, text=movie_data.title, font=("Arial", 12))
        label_title.place(x=x, y=y_pos)

        poster_path = movie_data.poster_path
        if poster_path:
            poster_url = f"https://image.tmdb.org/t/p/w500{poster_path}"
            response = requests.get(poster_url)
            img_data = Image.open(BytesIO(response.content))

            img_data = img_data.resize((150*2, 225*2), Image.LANCZOS)  # Redimensionne l'affiche
            img = ImageTk.PhotoImage(img_data)
            label_image = tk.Label(root, image=img)
            label_image.image = img
            label_image.place(x=x, y=y_pos + 30)
        else:
            print("Image not found")
    else:
        print("Film not found")


# Window init
root = tk.Tk()
root.title("Film Arena")

window_width = 1280
window_height = 1080
#set the window in middle
root.geometry(f"{window_width}x{window_height}")
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
x = (screen_width - window_width) // 2
y = (screen_height - window_height) // 2
root.geometry(f"{window_width}x{window_height}+{x}+{y}")
root.resizable(False, False)


# game :

def read_db(file_name):
    array = []
    try:
        with open(file_name, "r") as file:
            array = [line.strip() for line in file]
    except FileNotFound:
        print(f"Error: {file_name} not found")
    except ImpossibleRead:
        print("Error: impossible reading")
    return array

def game():
    btn.place_forget()
    database = read_db("database")
    random.shuffle(database)
    choice = database[0]
    random.shuffle(database)
    display_film(choice, 500)

    

film_left_x = 300
film_right_x = 680

btn = tk.Button(root, text="Fight !", command=game)
btn.place(x=(window_width/2)-50, y=550)

root.config(bg="black")





root.mainloop()