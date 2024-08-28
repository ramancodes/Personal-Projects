from pygame import mixer


def music_on_loop(file, stopper):
    mixer.init()
    mixer.music.load(file)
    mixer.music.play()
    while True:
        a = input()
        if a == stopper:
            mixer.music.stop()
            break


if __name__ == '__main__':
    music_on_loop("Maan Meri Jaan_320(PagalWorld.com.se).mp3", "stop")
