#include "goose_sim/scl/scl_parser.hpp"

#include <pugixml.hpp>
#include <stdexcept>

namespace goose_sim::scl {

std::vector<model::IedModel> SclParser::parse_file(const std::string& path) const {
    pugi::xml_document doc;
    auto result = doc.load_file(path.c_str());
    if (!result) {
        throw std::runtime_error("Failed to parse SCL file: " + path);
    }

    std::vector<model::IedModel> ieds;
    auto scl = doc.child("SCL");
    for (auto ied_node : scl.children("IED")) {
        model::IedModel model;
        model.name = ied_node.attribute("name").as_string();

        for (auto ap : ied_node.children("AccessPoint")) {
            auto server = ap.child("Server");
            for (auto ld : server.children("LDevice")) {
                auto ln0 = ld.child("LN0");
                for (auto ds : ln0.children("DataSet")) {
                    model::DataSet set;
                    set.reference = model.name + "/" + ld.attribute("inst").as_string() + "/" + ds.attribute("name").as_string();
                    for (auto fcda : ds.children("FCDA")) {
                        model::DataAttributeValue value;
                        value.path = std::string(fcda.attribute("ldInst").as_string()) + "/" + fcda.attribute("lnClass").as_string() + "." + fcda.attribute("doName").as_string() + "." + fcda.attribute("daName").as_string();
                        set.values.push_back(std::move(value));
                    }
                    model.datasets.emplace(set.reference, std::move(set));
                }

                for (auto gse : ln0.children("GSEControl")) {
                    model::GooseControlBlock block;
                    block.ied_name = model.name;
                    block.ld_inst = ld.attribute("inst").as_string();
                    block.cb_name = gse.attribute("name").as_string();
                    block.data_set_ref = gse.attribute("datSet").as_string();
                    block.go_id = gse.attribute("appID").as_string();
                    model.publishers.push_back(std::move(block));
                }
            }
        }

        ieds.push_back(std::move(model));
    }

    return ieds;
}

}  // namespace goose_sim::scl
