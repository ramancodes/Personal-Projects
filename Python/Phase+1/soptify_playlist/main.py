from bs4 import BeautifulSoup
import requests
import spotipy
from spotipy.oauth2 import SpotifyOAuth

CLIENT_ID = "dd2455b907494a39919976f776d4fc43"
CLIENT_SECRET = "dd2455b907494a39919976f776d4fc43"

# Scraping Billboard 100
user_date = input("Which year do you want to travel to? Type the data in this format YYYY-MM-DD: ")
response = requests.get("https://www.billboard.com/charts/hot-100/"+user_date)
soup = BeautifulSoup(response.text, "html.parser")
song_names = soup.find_all(name="h3", id="title-of-a-story", class_="c-title a-no-trucate a-font-primary-bold-s "
                                                                    "u-letter-spacing-0021 lrv-u-font-size-18@tablet "
                                                                    "lrv-u-font-size-16 u-line-height-125 "
                                                                    "u-line-height-normal@mobile-max "
                                                                    "a-truncate-ellipsis u-max-width-330 "
                                                                    "u-max-width-230@tablet-only")
songs = [song.getText().replace("\t", "").replace("\n", "") for song in song_names]
# for song in songs:
#     print(song)


# Spotify Authentication
sp = spotipy.Spotify(
    auth_manager=SpotifyOAuth(
        scope="playlist-modify-private",
        redirect_uri="http://example.com",
        client_id=CLIENT_ID,
        client_secret=CLIENT_SECRET,
        show_dialog=True,
        cache_path="token.txt"
    )
)
user_id = sp.current_user()["id"]
print(user_id)


# Searching Spotify for songs by title
song_uris = []
year = user_date.split("-")[0]
for song in song_names:
    result = sp.search(q=f"track:{song} year:{year}", type="track")
    print(result)
    try:
        uri = result["tracks"]["items"][0]["uri"]
        song_uris.append(uri)
    except IndexError:
        print(f"{song} doesn't exist in Spotify. Skipped.")


# Creating a new private playlist in Spotify
playlist = sp.user_playlist_create(user=user_id, name=f"{user_date} Billboard 100", public=False)
print(playlist)


# Adding songs found into the new playlist
sp.playlist_add_items(playlist_id=playlist["id"], items=song_uris)
