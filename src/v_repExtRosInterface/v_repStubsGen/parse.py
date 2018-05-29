import xml.etree.ElementTree as ET
import model

def parse(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    return model.Plugin(root)

