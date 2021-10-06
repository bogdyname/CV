from PyQt5.QtWidgets import QWidget

class MainWindow(QWidget):

    def __init__(self):
        self.main_window = QWidget()

    def init_ui(self):
        self.main_window.resize(250, 150)
        self.main_window.move(300, 300)
        self.main_window.setWindowTitle('Financial Manager')
        self.main_window.show()